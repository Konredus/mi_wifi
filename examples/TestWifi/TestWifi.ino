// Libreria creada por Andreas Haller
// Para la https://tribumaker.com/

#include <ESP8266WiFi.h>      // Librería que nos da capacidades WiFi.

// Agregamos nuestras credenciales de WiFi a las variables
const char ssid[] = "MiNombreDeRed";
const char password[] = "MiContraseña";

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

}

void loop() {

}
