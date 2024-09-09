#include <Servo.h>  //LIBRERIA PARA SERVO MOTOR
//CLASE 30 https://www.youtube.com/watch?v=GUhPrO1BEJ0&list=PLyLh25DppBIe40j3VBAslnVfs4Pz-B3ZB&index=32&ab_channel=JohannPerezE
// MOVIMIENTO DE UN SERVO MOTOR
//CABLE MARRON= GND CABLE ROJO =5V CABLE NARANJA=INPUT

int servoPin = 9;
int servoPos = 0;  //Variable para angulo de posicion
Servo myServo;     //Nombre para el servo
int lightPin = A0;
int lightVal;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);  //inicializar servo
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
}

void loop() {
  lightVal = analogRead(lightPin);
  myServo.write(servoPos);
}
