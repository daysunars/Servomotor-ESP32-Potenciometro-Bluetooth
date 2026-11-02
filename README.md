# ESP32 + Servomotor SG90

Proyecto que permite controlar un servomotor SG90 mediante una placa ESP32 utilizando dos métodos independientes:

1. **Control con potenciómetro:** permite modificar el ángulo del servomotor girando un potenciómetro.
2. **Control mediante Bluetooth:** permite enviar un ángulo desde un celular Android al ESP32 para posicionar el servomotor.

Cada método cuenta con su propio programa (`.ino`). Se debe cargar únicamente uno de ellos a la vez en el ESP32.

## Archivos del proyecto

| Archivo | Descripción |
|---|---|
| `servo_potenciometro.ino` | Programa para controlar el servomotor mediante un potenciómetro. |
| `servo_bluetooth.ino` | Programa para controlar el servomotor desde un celular Android mediante Bluetooth. |
| `README.md` | Documentación del proyecto, descripción y conexiones. |

## Tabla de conexiones

| Componente | Cable / Terminal | Conexión ESP32 |
|---|---|---|
| Servomotor SG90 | Marrón (GND) | GND común |
| Servomotor SG90 | Rojo (VCC) | Fuente externa de 5 V |
| Servomotor SG90 | Naranja (Señal) | GPIO 18 |
| Potenciómetro | Terminal central | GPIO 34 |
| Potenciómetro | Terminal exterior | GND |
| Potenciómetro | Terminal exterior | 3.3 V |

## Conexión Bluetooth

Para controlar el servomotor desde el celular se utiliza la aplicación [Arduino Bluetooth Controller](https://play.google.com/store/search?q=arduino+bluetooth+controller&c=apps).

### Pasos para conectar

1. Cargar el programa `servo_bluetooth.ino` en el ESP32.
2. Mantener el ESP32 encendido y activar el Bluetooth del celular.
3. Abrir la aplicación Arduino Bluetooth Controller.
4. Seleccionar **Plugins** para acceder a los dispositivos Bluetooth.
5. Buscar y seleccionar `ESP32_Servo` para establecer la conexión.
6. Una vez conectado, entrar en la opción **Terminal**.
7. Escribir un número entre `0` y `180` en el campo de envío.
8. Enviar el número utilizando la opción de envío o Enter

### Comandos de control

| Comando enviado | Movimiento del servomotor |
|---|---|
| `0` | 0° |
| `45` | 45° |
| `90` | 90° |
| `135` | 135° |
| `180` | 180° |

## Consideraciones

- El servomotor debe alimentarse con una fuente externa regulada de 5 V.
- Conectar el GND de la fuente externa al GND del ESP32 para compartir tierra común.
- Los terminales exteriores del potenciómetro pueden intercambiarse; esto solo cambia el sentido de giro.
- El potenciómetro únicamente se necesita para el programa `servo_potenciometro.ino`.
- Para `servo_bluetooth.ino` se necesita un celular y la aplicación Arduino Bluetooth Control.
- El control Bluetooth utiliza Bluetooth clásico (SPP), compatible con placas ESP32-WROOM-32.


