#include <WiFi.h>
#include <WebServer.h>
char* ssid = "Aula 1";
char* pdw = "Horus.2025";

#define LED 4

WebServer servidor(80);

//Páginas

String home = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Document</title></head><body><h1>Hola Mundo</h1><h2>Esta es mi primera página</h2><a href=\"/segunda\">Ir a la segunda página</a></body></html>";
String segunda = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Segunda página</title></head><body><h1>Esta es la segunda página</h1></body></html>";
String encender ="";
void setup()
{
  pinMode(LED, OUTPUT);
  
  Serial.begin(115200);
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
  servidor.on("/led_on",handle_Encender);
  servidor.on("/led_off",handle_Apagar);

  servidor.begin();
  Serial.println("Servidor web iniciado");  
}

void loop() 
{
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
  digitalWrite(LED, HIGH);
  servidor.send(200,"text/html","");
}


void handle_Apagar()
{
  digitalWrite(LED, LOW);
  servidor.send(200,"text/html","");
}
