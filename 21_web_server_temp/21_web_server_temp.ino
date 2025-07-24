#include <WiFi.h>
#include <WebServer.h>
char* ssid = "Aula 1";
char* pdw = "Horus.2025";

#include <DHT.h>

#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float temp;
float hum; 

WebServer servidor(80);

//Páginas

String home = "<!DOCTYPE html><html lang=\"es\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Primera página</title></head><body><h1>Hola Mundo</h1><h2>Esta es mi primera página</h2><a href=\"/segunda\">Ir a la segunda página</a></body></html>";
String segunda = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Segunda página</title></head><body><h1>Esta es la segunda página</h1></body></html>";
String temperatura = "<!DOCTYPE html><html lang=\"es\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Primera página</title></head><body><h1>Temperatura y humedad</h1><h2>Temperatura: ##temp##</h2><h2>Humedad: ##hum##</h2></body></html>";


void setup()
{
 
  Serial.begin(115200);
  dht.begin();
   
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,pdw);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n");
  Serial.print("Conectado a la IP: ");
  Serial.println(WiFi.localIP());


  // Solicitud de web

  servidor.on("/", handle_OnConnect);
  servidor.on("/segunda",handle_Segunda);
  servidor.on("/tem",handle_Temp);
  

  servidor.begin();
  Serial.println("Servidor web iniciado");  
}

void loop() 
{
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println("\t Humedad: " + String(hum));
   
  delay(1000);
  
    
  servidor.handleClient();
}

// Funciones de respuesta a las paginas web

void handle_OnConnect()
{
  servidor.send(200,"text/html", home);
}

void handle_Segunda()
{
  servidor.send(200,"text/html",segunda);
}

void handle_Encender()
{
  
  servidor.send(200,"text/html","");
}


void handle_Apagar()
{
  
  servidor.send(200,"text/html","");
}

void handle_Temp()
  {
    temp = dht.readTemperature();
    hum = dht.readHumidity();
    temperatura.replace("##temp##", String(temp));
    temperatura.replace("##hum##",String(hum));
    servidor.send(200,"text/html",temperatura);
  }
