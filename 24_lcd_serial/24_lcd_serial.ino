#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 13
#define SCL 14
#define ADDR 0x27 //La otra es 0x3F

LiquidCrystal_I2C lcd(ADDR,16,2);

//
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float temp;
float hum; 

void setup()
{
 Serial.begin(115200);
 dht.begin();
 
 Serial.begin(115200);
 Wire.begin(SDA,SCL);
 lcd.init();
 lcd.clear();
 lcd.backlight();
}

void loop()
{
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: " + String(temp) + (char)223 +"C");
  lcd.setCursor(0,1);
  lcd.print("Hum: " + String(hum) + "%");
 
  delay(1000);


 

}