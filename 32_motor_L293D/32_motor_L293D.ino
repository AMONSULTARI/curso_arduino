#define VELOCIDAD 14
#define DIRPIN_1 12
#define DIRPIN_2 13

#define ROJO 2
#define AZUL 32
#define VERDE 33

void setup() 
{
 Serial.begin(115200);
  
 pinMode(VELOCIDAD, OUTPUT);
 pinMode(DIRPIN_1, OUTPUT);
 pinMode(DIRPIN_2, OUTPUT);

 pinMode(ROJO, OUTPUT);
 pinMode(AZUL, OUTPUT);
 pinMode(VERDE, OUTPUT);

}

void loop() 
{
  Serial.println("Girando en una dirección");

  analogWrite(VELOCIDAD, 100);
  //digitalWrite(VELOCIDAD, HIGH); //ENCENDEMOS EL MOTOR
  digitalWrite(DIRPIN_1, 0);
  digitalWrite(DIRPIN_2, 1);
  digitalWrite(VERDE, HIGH);
  digitalWrite(ROJO, LOW);
  digitalWrite(AZUL, LOW);

  delay(5000);

  analogWrite(VELOCIDAD, LOW); //APAGAMOS EL MOTOR
  digitalWrite(ROJO, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  

  delay(5000);

  Serial.println("Girando en otra dirección");
  analogWrite(VELOCIDAD, 100);
 //digitalWrite(VELOCIDAD, HIGH); //ENCENDEMOS EL MOTOR
  digitalWrite(DIRPIN_1, 1);
  digitalWrite(DIRPIN_2, 0);
  digitalWrite(AZUL, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(ROJO, LOW);
  

  delay(5000);

  Serial.println("Motor parado");

  analogWrite(VELOCIDAD, LOW); //APAGAMOS EL MOTOR
  digitalWrite(ROJO, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  
  delay(5000);

}
