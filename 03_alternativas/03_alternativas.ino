 int nota = 5;

void setup() {
 
Serial.begin(115200);
delay(500);



}
void loop() 
{
  if(nota<5)
  {
   Serial.print("Suspenso"); 
  }
  else
  {
   if(nota<7)
   {
   Serial.print("Aprobado");
   }
 
  else
  {
   if(nota<9)
   Serial.print("Notable")
   else
   {
   Serial.print("Sobresaliente")
  }
  }
  }
  }

}





