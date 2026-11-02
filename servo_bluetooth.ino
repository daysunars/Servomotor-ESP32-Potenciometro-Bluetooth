
#include <ESP32Servo.h>
#include "BluetoothSerial.h"

Servo myServo;
BluetoothSerial SerialBT;

const int servoPin = 18;

int angle = 90;
String receivedData = "";

unsigned long lastReceived = 0;

void setup() {
  Serial.begin(9600);

  SerialBT.begin("ESP32_Servo");

  myServo.setPeriodHertz(50);
  myServo.attach(servoPin, 500, 2400);

  myServo.write(angle);

  Serial.println("Bluetooth iniciado");
  SerialBT.println("ESP32 conectado");
}

void loop() {

  while (SerialBT.available()) {
    char receivedChar = SerialBT.read();

    if (receivedChar == '\n' || receivedChar == '\r') {
      processData();
    } 
    else if (isDigit(receivedChar)) {
      receivedData += receivedChar;
      lastReceived = millis();
    }
  }

  // Procesar si termina el envío sin salto de línea
  if (receivedData.length() > 0 &&
      millis() - lastReceived > 150) {
    processData();
  }
}

void processData() {

  if (receivedData.length() > 0) {

    int newAngle = receivedData.toInt();

    if (newAngle >= 0 && newAngle <= 180) {

      angle = newAngle;
      myServo.write(angle);

      Serial.print("Angulo: ");
      Serial.println(angle);

      SerialBT.print("Angulo recibido: ");
      SerialBT.println(angle);
    }

    receivedData = "";
  }
}
