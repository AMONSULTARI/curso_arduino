
int numeros[5];
int otro[] = {1,2,3,4,5};

void setup() {
  Serial.begin(115200);

  for(int i=0; i<5; i++){
    numeros[i] = otro[i];
  }

  for(int i=0; i<5; i++){
    Serial.print("Numeros: ");
    Serial.println(numeros[i]);
  }

}

void loop() {
  

}
