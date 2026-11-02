
#include <ESP32Servo.h>

Servo myServo;

// Pines
const int potPin = 34;
const int servoPin = 18;

// Variables
int potVal;
int angle;

void setup() {
  myServo.setPeriodHertz(50);
  myServo.attach(servoPin, 500, 2400);

  Serial.begin(9600);
}

void loop() {

  // Leer el potenciometro
  potVal = analogRead(potPin);

  // Convertir el valor a un angulo
  angle = map(potVal, 0, 4095, 0, 180);

  // Mostrar los valores
  Serial.print("potVal: ");
  Serial.print(potVal);

  Serial.print(", angle: ");
  Serial.println(angle);

  // Mover el servomotor
  myServo.write(angle);

  delay(15);
}
