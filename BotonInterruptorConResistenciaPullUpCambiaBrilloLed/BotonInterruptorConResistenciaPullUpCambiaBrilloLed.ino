//CLASE 29 https://www.youtube.com/watch?v=ajzHQpJDiRw&list=PLyLh25DppBIe40j3VBAslnVfs4Pz-B3ZB&index=31&ab_channel=JohannPerezE
//DOS BOTONES CON RESISTENCIAS PULL UP INTERRUPTORES PARA VARIAS BRILLO EN UN LED
//SE DEBEN CREAR VARIABLES PARA GUARDAR LOS VALORES DE LOS BOTONES
//0 =ENCENDIDO 1 =APAGADO

int pinButton1 = A0;
int pinButton2 = A1;
int ledPin = 11;
int buzzPin = 8;
int buttonNew1;
int buttonNew2;
int dtButton = 200;
int dtBuzz = 200;
int ledBright = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(pinButton1, INPUT);
  pinMode(pinButton2, INPUT);
}

void loop() {
  buttonNew1 = digitalRead(pinButton1);
  buttonNew2 = digitalRead(pinButton2);
  Serial.print(" Boton 1 = : ");
  Serial.print(buttonNew1);
  Serial.print(" Boton  =2 : ");
  Serial.println(buttonNew2);
  Serial.print(" Brillo :");
  Serial.println(ledBright);
  delay(dtButton);

  if (buttonNew1 == 0) {
    ledBright = ledBright - 15;
    analogWrite(ledPin,ledBright);
  }

  else if (buttonNew2 == 0) {
    ledBright = ledBright + 15;
    analogWrite(ledPin,ledBright);
  }
  else if (ledBright < 0) {
    ledBright = 0;
    digitalWrite(buzzPin, HIGH);
    delay(dtBuzz);
    digitalWrite(buzzPin, LOW);
    analogWrite(ledPin,ledBright);
  }
  else if (ledBright > 255) {
    ledBright = 255;
    digitalWrite(buzzPin, HIGH);
    delay(dtBuzz);
    digitalWrite(buzzPin, LOW);
    analogWrite(ledPin,ledBright);
  }
}
