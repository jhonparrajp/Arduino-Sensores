#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int trigPin = 12;
int echoPin = 11;
int buzzPin = 8;
int motorPin=7;;

long duracion;
int distancia;

int ultimaDistancia = 0;
int dtBuzz = 200;
int dtLcd = 500;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin,OUTPUT);
  pinMode(motorPin,OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
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
  digitalWrite(motorPin,HIGH);

  if (distancia < 10 && distancia > 7) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DETECCION  ");
    lcd.setCursor(0, 1);
    lcd.print("BOTELLA 450 ML");

    digitalWrite(motorPin,LOW);
    digitalWrite(buzzPin,HIGH);
    delay(dtBuzz);
    digitalWrite(buzzPin,LOW);
    delay(dtBuzz);
   
  }

    else if (distancia > 10 && distancia < 15) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DETECCION  ");
    lcd.setCursor(0, 1);
    lcd.print("BOTELLA 250 ML");

    digitalWrite(motorPin,LOW);
    digitalWrite(buzzPin,HIGH);
    delay(dtBuzz);
    digitalWrite(buzzPin,LOW);
    delay(dtBuzz);
    
  }

    else   {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ESPERANDO  ");
    lcd.setCursor(0, 1);
    lcd.print("BOTELLA");
    digitalWrite(motorPin,1);
   
  }


  delay(dtLcd);
}
