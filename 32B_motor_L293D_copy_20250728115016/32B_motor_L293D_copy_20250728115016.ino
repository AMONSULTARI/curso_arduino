#include <LiquidCrystal_I2C.h>
#include <Wire.h>


#define VELOCIDAD 14
#define DIRPIN_1 12
#define DIRPIN_2 13

//Estados posibles
#define PARO 0
#define DERECHA 1
#define IZQUIERDA 2

#define ROJO 2
#define AZUL 32
#define VERDE 33

#define POT 15

#define SDA 26
#define SCL 27
#define ADDR 0x27

LiquidCrystal_I2C lcd(ADDR,16,2);


void setup() 
{
  Serial.begin(115200);

  pinMode(VELOCIDAD, OUTPUT);
  pinMode(DIRPIN_1, OUTPUT);
  pinMode(DIRPIN_2, OUTPUT);

  pinMode(ROJO, OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(VERDE, OUTPUT);

  pinMode(POT, INPUT);

}

void loop() 
{
  cambioEstado(DERECHA);
  delay(5000);

  cambioEstado(PARO);
  delay(2000);

  cambioEstado(IZQUIERDA);
  delay(5000);

  cambioEstado(PARO);
  delay(2000);

  

}

void cambioEstado(int estadoNuevo)
{
  lcd.clear();
  
  switch(estadoNuevo){
  case PARO:
  Serial.println("Motor parado");
  analogWrite(VELOCIDAD, 0); // Aapagamos el motor
  digitalWrite(ROJO, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);

  break;

  case IZQUIERDA:
  //digitalWrite(VELOCIDAD, HIGH); // Encendemos el motor
  Serial.println("Girando en la dirección IZQUIERDA.");
  analogWrite(VELOCIDAD, leerPot());
  digitalWrite(DIRPIN_1, 0);
  digitalWrite(DIRPIN_2, 1);
  digitalWrite(AZUL, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(ROJO, LOW);

  break;

  case DERECHA:
  //digitalWrite(VELOCIDAD, HIGH); // Encendemos el motor
  Serial.println("Girando en la dirección DERECHA.");
  analogWrite(VELOCIDAD, leerPot());
  digitalWrite(DIRPIN_1, 1);
  digitalWrite(DIRPIN_2, 0);  
  digitalWrite(VERDE, HIGH);
  digitalWrite(ROJO, LOW);
  digitalWrite(AZUL, LOW);

  break;
  }
  
}

int leerPot()
{
  int valorPot = 0;
  int valorVel = 0;

  valorPot = analogRead(POT);
  valorVel = map(valorPot, 0, 4096, 80, 255);
  return valorVel;

  Serial.println("Velocidad: " + String(valorPot));

  Serial.println("Velocidad: " + String(valorVel));

  //int valuePot = analogRead(POT);
}

void escribeLCD(String mensaje, int fila)
{
  //lcd.clear();
  lcd.setCursor(0,fila);
  lcd.print(mensaje);
}
