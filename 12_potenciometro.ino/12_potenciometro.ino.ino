#define POTEN 4
#define LED 2

#define POTEN2 14
#define BUZZER 12

void setup() {
  
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  pinMode(POTEN, INPUT);

  pinMode(BUZZER, OUTPUT);
  pinMode(POTEN2, INPUT);

}

void loop() {
 
  int valuePoten = analogRead(POTEN);
  int valueLed = valuePoten / 16;

  // Serial.println("Valor del potenciómetro: " + String(valuePoten));
  // Serial.println("Valor del led: " + String(valueLed));

  analogWrite(LED, valueLed);

  int valuePoten2 = analogRead(POTEN2);

  digitalWrite(BUZZER, HIGH);

  delay(valuePoten2);
  digitalWrite(BUZZER, LOW);
  // tone(BUZZER, valuePoten2);
  delay(valuePoten2);



}
