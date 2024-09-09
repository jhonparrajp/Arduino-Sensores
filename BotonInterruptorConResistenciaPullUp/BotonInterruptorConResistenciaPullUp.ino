//CLASE 28 https://www.youtube.com/watch?v=tgWNMA28wXw&list=PLyLh25DppBIe40j3VBAslnVfs4Pz-B3ZB&index=30&ab_channel=JohannPerezE
//UTILIZAR UN BOTON PARA ENCENDER GUARDAR EL VALOR , APAGAR Y GUARDAR EL VALOR

int ledPin = 12;
int buttonPin = 4;
int ledState = 0;
int buttonOld = 1;
int buttonNew;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonNew = digitalRead(buttonPin);
  if (buttonNew == 0 && buttonOld == 1) {
    if (ledState == 0) {
      digitalWrite(ledPin, 1);
      ledState=1;
    }
    else{
      digitalWrite(ledPin,0);
      ledState=0;
    }
  }
  buttonOld=buttonNew;
}
