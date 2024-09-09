#include <Wire.h> 
#include <LiquidCrystal_I2C.h>    //https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin = A0;
float volt;
float ntu;

void setup()
{
  Serial.begin(115200);
  //lcd.begin();
  lcd.backlight();
}

void loop()
{
    volt = 0;
    for(int i=0; i<1000; i++)
    {
        volt += ((float)analogRead(sensorPin)/1023)*5;
    }
    volt = volt/1000;
    volt = round_to_dp(volt, 2);
    if(volt < 2.5) {
        ntu = 500;
    } else {
        ntu = -1120.4*square(volt) + 5742.3*volt - 4353.8; 
    }
    
    // Limitar el valor de NTU a 500
    if (ntu > 500) {
        ntu = 500;
    }
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(volt);
    lcd.print(" V");
    Serial.print(" V");
    Serial.print(volt);
    Serial.println(ntu);
    lcd.setCursor(0,1);
    lcd.print(ntu);
    lcd.print(" NTU");
    delay(1000);
}

float round_to_dp(float in_value, int decimal_place)
{
  float multiplier = powf(10.0f, decimal_place);
  in_value = roundf(in_value * multiplier) / multiplier;
  return in_value;
}
