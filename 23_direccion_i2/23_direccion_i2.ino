#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 13
#define SCL 14
#define ADDR 0x27 //La otra es 0x3F

LiquidCrystal_I2C lcd(ADDR,16,2);



void setup() 
{
  Serial.begin(11520);
  delay(1000);
  //byte count = 0;

  Wire.begin(SDA, SCL);
  for (byte i = 0; i < 120; i++)
  {
    Wire.beginTransmission(i);
    if(Wire.endTransmission() == 0)
    {
      Serial.print("Dirección encontrada: ");
      //Serial.print(i, DEC);
      Serial.print("0x");
      Serial.print(i, HEX);
      //count++;
      delay(1);
    }
  }
  //Serial.print("\n");
  //Serial.print("Encontrados " + String(count));
}

void loop() {
  // put your main code here, to run repeatedly:

}
