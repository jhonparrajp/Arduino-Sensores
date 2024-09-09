//RESISTENCIA PULL UP , LA RESISTENCIA VA EN EL POSITIVO
//SE REALIZA UNA LECTURA DIGITAL
//BOTON SIN PRESIONAR =1
//BOTON PRESIONADO =0
int buttonPin = 4;  //Se manda a un pin digital
int ledPin = 12;
int buttonRead;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {

  buttonRead = digitalRead(buttonPin);  //lectura digital
  Serial.println(buttonRead);

  if (buttonRead == 1) {

    digitalWrite(ledPin, LOW);

  } else if (buttonRead == 0) {

    digitalWrite(ledPin, HIGH);
  }
}
