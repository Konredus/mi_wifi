// Libreria creada por Andreas Haller
// Para la https://tribumaker.com/

#include <ESP8266WiFi.h>      // Librería que nos da capacidades WiFi.
#include <ESP8266WebServer.h> // Librería que nos permite crear y manejar un servidor.

ESP8266WebServer server(80);  // Creamos nuestro servidor y definimos el puerto 80.

void setup() {
  Serial.begin(115200);     // Iniciamos el puerto serial

  WiFi.mode(WIFI_AP);      // Ponemos el ESP en modo AP (Access point)
  WiFi.softAP("ESP8266");    // Ponemos que nombre queremos que tenga la red (creara una red abierta sin contraseña)

  Serial.println("Red creada!");
  Serial.println("Abre y escanea con tu dispositivo WIFI.");
  Serial.println("Cuando encuentres la RED >ESP8266< conectate a ella.");
  Serial.print("Luego abre la IP: ");
  Serial.print(WiFi.softAPIP());
  Serial.println(" en tu navegador");

  // Esta función nos permite enviar datos al cliente que se conecte a nuestro servidor
  server.on("/", []() {
    server.send(200, "text/plain", "Hola Mundo!");  // Enviamos "Hola Mundo!" como texto
  });

  server.begin();     // Una vez que definimos todas nuestras páginas, iniciamos el servidor
  Serial.println("Servidor iniciado");  // Avisamos por puerto serie.
}

void loop() {
  server.handleClient();
}
