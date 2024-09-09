#include <DHT.h>
#include <DHT_U.h>

//Primero que tipo de sensor estamos usando
#define Type DHT11
//en que pin esta
int dhtPin = 7;
//parametros nombre y pin
DHT HT(dhtPin, Type);
//Temperatura y humedad se llen en floats
int humidity;
float tempC;
float tempF;
int dt = 600;

void setup() {
  Serial.begin(115200);
  HT.begin();
}

void loop() {
  humidity = HT.readHumidity();
  tempC=HT.readTemperature();
  tempF=HT.readTemperature(true);

  Serial.print("Humedad Relativa: ");
  Serial.print(humidity);
  Serial.print(" %");
  Serial.print(" Temperatura: ");
  Serial.print(tempC);
  Serial.print(" °C/ ");
  Serial.print(tempF);
  Serial.println(" °F ");
  delay(dt);
}
