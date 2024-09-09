#include <Stepper.h>

//CLASE 34 https://www.youtube.com/watch?v=XixNg9DGxgo&list=PLyLh25DppBIe40j3VBAslnVfs4Pz-B3ZB&index=36&ab_channel=JohannPerezE
//MOTOR PASO-PASO ,5V , SE DEBE CONECTAR CON SU DRIVER Y USAR UNA FUENTE EXTERNA
//IN1=PIN DIGITAL IN2=PIN DIGITAL IN3=PIN DIGITAL IN4=PIN DIGITAL
//SE DEBE UTILIZAR LA LIBRERIA STEPPER
//2048 STEPS PARA UN GIRO DE 360
int stepsPerRevolution = 2048;
int motSpeed = 10;  //VELOCIDAD DADA EN REVOLUCIONES POR MINUTO
//SE LE DA NOMBRE AL SERVO Y SE PASA LA VARIABLE DE GIRO Y LOS PINES QUE SE UTILIZAN
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int dt = 500;


void setup() {
  // put your se(tup code here, to run once:
  myStepper.setSpeed(motSpeed);  //VELOCIDAD DEL STEPPER
}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.step(stepsPerRevolution);  //que de una vuelta completa
  delay(dt);
  myStepper.step(-stepsPerRevolution); //girando en sentido contrario
  delay(dt);
}
