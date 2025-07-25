#include <ESP32Servo.h>
#include <BluetoothSerial.h>

#define VERDE 14
#define ROJO 13

#define pinServo 15

Servo miServo;
BluetoothSerial serialBT;

String entrada = "";
String secreto = "1234";
bool primeraVez = true;

void setup()
{
 Serial.begin(115200);
 pinMode(ROJO, OUTPUT);
 pinMode(VERDE, OUTPUT);
   
  // BLUETOOTH

  serialBT.begin("Caja_fuerte_María");

  // SERVO

 miServo.setPeriodHertz(50);
 miServo.attach(pinServo, 500, 2500); 
 miServo.write(0);

 digitalWrite(ROJO, HIGH);
 digitalWrite(VERDE, LOW);
}

void loop() 
{
  
  if(primeraVez)
  {
    serialBT.println("Introduzca la clave.");
    primeraVez = false;
  }
  
  
  if(serialBT.available() > 0)
  {
    entrada = serialBT.readStringUntil('\n');
    entrada.trim();
    if(entrada == secreto)
    {
      serialBT.println("Clave correcta");
      miServo.write(90);

      digitalWrite(ROJO, LOW);
      digitalWrite(VERDE, HIGH);
      delay(5000);

      serialBT.println("Puerta cerrada");
      digitalWrite(ROJO, HIGH);
      digitalWrite(VERDE, LOW);
      miServo.write(0);

    }
      else 
      {
        serialBT.println("Clave incorrecta, Prueba otra vez.");
      }

  }

}
