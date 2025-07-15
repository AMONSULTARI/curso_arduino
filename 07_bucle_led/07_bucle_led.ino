#define LED 2
#define ZUMBADOR 15

void setup() 
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(ZUMBADOR, OUTPUT);
}

int duracion = 20;
void loop() 
{
  for(int i = 0; 1 < 100; i++)
  {
   digitalWrite(LED, HIGH);
   digitalWrite(ZUMBADOR, HIGH);
   delay(duracion);
   duracion = duracion +i * 10;
   digitalWrite(LED, LOW);
   digitalWrite(ZUMBADOR, LOW);
   delay(duracion);
  }
    
}
