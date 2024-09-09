 /***********Notice and Trouble shooting***************
 1. This code is tested on Arduino Uno with Arduino IDE 1.0.5 r2 and 1.8.2.
 2. Calibration CMD:
     enter -> enter the calibration mode
     cal:tds value -> calibrate with the known tds value(25^c). e.g.cal:707
     exit -> save the parameters and exit the calibration mode
 ****************************************************/
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <EEPROM.h>
#include "GravityTDS.h"
#include <DHT.h>
#include <DHT_U.h>

#define TdsSensorPin A1
#define Type DHT11
int dhtPin = 7;
DHT HT(dhtPin, Type);
int humidity;
float tempC;
float tempF;
int dt = 2000;

GravityTDS gravityTds;
LiquidCrystal_I2C lcd(0x27, 16, 2);
float temperature = 25,tdsValue = 0;

void setup()
{
    Serial.begin(115200);
    HT.begin();
    gravityTds.setPin(TdsSensorPin);
    gravityTds.setAref(5.0);  //reference voltage on ADC, default 5.0V on Arduino UNO
    gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
    gravityTds.begin();  //initialization
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Conductividad E ");
    lcd.setCursor(0, 1);
    lcd.print("  TDS ");
    delay(2000);
}

void loop()
{
    //temperature = readTemperature();  //add your temperature sensor and read it
    gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
    gravityTds.update();  //sample and calculate
    tdsValue = gravityTds.getTdsValue();  // then get the value
    Serial.print(tdsValue,0);
    Serial.println(" ppm");
    Serial.print(tdsValue*2);
    Serial.println(" Us/Cm");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CE: ");
    lcd.print(tdsValue*2);
    lcd.print(" Us/Cm");
    lcd.setCursor(0, 1);
    lcd.print("TDS: ");
    lcd.print(tdsValue);
    lcd.print(" Ppm");
    delay(dt);
    //DHT11
    humidity = HT.readHumidity();
    tempC=HT.readTemperature();
    tempF=HT.readTemperature(true);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(tempC);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("Humedad: ");
    lcd.print(humidity);
    lcd.print("%");

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
