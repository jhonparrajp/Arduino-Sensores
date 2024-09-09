#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int trigPin = 9;
int echoPin = 7;

long duracion;
int distancia;

int ultimaDistancia = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
    lcd.print("Temperatura ");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH);
  distancia = (duracion * 0.034) / 2;

  Serial.println(distancia);

  if (distancia != ultimaDistancia) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distancia: ");
    lcd.print(distancia);
    lcd.print(" Cm ");
    ultimaDistancia=distancia;
  }



  delay(500);
}
