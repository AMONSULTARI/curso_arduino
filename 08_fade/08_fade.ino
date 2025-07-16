#define LED_ROJO 15
#define LED_AZUL 13

void setup() 
{
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
}

void loop() 
{
  /* 
  digitalWrite(LED_ROJO, HIGH);
  delay(1000);
  digitalWrite(LED_ROJO, LOW);
  delay(1000);
  */

 for(int i = 0; i <= 255; i++)
 {
   analogWrite(LED_ROJO, i);
   analogWrite(LED_AZUL, 255-i);
   delay(5);
  } 
  
    delay(1000);

  for(int i = 255; i >= 0; i--)
 {
   analogWrite(LED_ROJO, i);
   analogWrite(LED_AZUL, 255-i);
   delay(5);
  } 
  delay(1000);
}
