// Libreria creada por Andreas Haller
// Para la https://tribumaker.com/

#include <ESP8266WiFi.h>      // Librería que nos da capacidades WiFi.
#include <ESP8266WebServer.h> // Librería que nos permite crear y manejar un servidor.
#include <mi_wifi.h>    // Esta librería contiene nuestras credenciales WiFi

ESP8266WebServer server(80);  // Creamos nuestro servidor y definimos el puerto 80.

void setup() {
  Serial.begin(115200);     // Iniciamos el puerto serial

  WiFi.mode(WIFI_STA);      // Ponemos el ESP en modo cliente (station)

  WiFi.begin(ssid, password);   // Agregamos nuestras credenciales de WiFi y pedimos que se conecte

  Serial.println("");
  Serial.println("");
  Serial.print("Conectando a WiFi ");

  // Este pequeño código evita que el programa inicie hasta que no se conecte al WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Una vez conectados, vamos a mostrar por Puerto Serie
  //la direccion IP que nos asigno el Router de nuestra casa
  Serial.println("Conectado!");
  Serial.print("Nuestra IP es: ");
  Serial.println(WiFi.localIP());

  // Esta función nos permite enviar datos al cliente que se conecte a nuestro servidor
  // La URL (dirección) que nos pide el cliente se escribe como parámetro de la función.
  // Si escribimos nuestra IP en el navegador, nos mostrara el mensaje.  
  server.on("/", []() {
    server.send(200, "text/plain", "Hola Mundo!");  // Enviamos "Hola Mundo!" como texto
  });

  server.begin();     // Una vez que definimos todas nuestras páginas, iniciamos el servidor
  Serial.println("Servidor iniciado");  // Avisamos por puerto serie.
}

void loop() {
  /*  Esta función se encarga de manejar todo lo relacionado con el servidor
      cada ves que la llamemos, va a verificar si hay alguna consulta al servidor
      y va a mandar la respuesta que hayamos definido en el setup
  */
  server.handleClient();
}
