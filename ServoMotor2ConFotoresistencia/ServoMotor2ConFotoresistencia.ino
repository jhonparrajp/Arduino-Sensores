#include <Servo.h>  //LIBRERIA PARA SERVO MOTOR
//CLASE 31 
// MOVIMIENTO DE UN SERVO MOTOR
//CABLE MARRON= GND CABLE ROJO =5V CABLE NARANJA=INPUT
//MOVER EL SERVO MOTOR CON LOS VALORES DE UNA FOTO RESISTENCIA
//SE DEBE REALIZAR EL CALCULO DE LA PENDIENTE PARA EL MOVIMIENTO
int servoPin = 9;
int servoPos ;  //Variable para angulo de posicion
Servo myServo;     //Nombre para el servo

int potPin = A0;
int potVal;
int dt = 500;
int light;
void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);  //inicializar servo
  Serial.begin(9600);
  pinMode(potPin, INPUT);
}

void loop() {

  potVal = analogRead(potPin);
  
  //Funcion map sirve para convertir parametro, la funcion requiere de 5 parametros
  //variable donde estaran los datos , y de que rango a que rango se quiere convertir
  servoPos = map(potVal,0,1023,0,170);
  myServo.write(servoPos);
  Serial.print("Potenciómetro: ");
  Serial.print(potVal);
  Serial.print(", Ángulo: ");
  Serial.println(servoPos);
  delay(dt);
}

