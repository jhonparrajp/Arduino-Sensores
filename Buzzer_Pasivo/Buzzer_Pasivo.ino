int buzzPin = 9;
float buzzDelay ;
int potPin = A0;
int potVal;
String msg1 = (" VALOR DE POTENCIOMETRO :");
String msg2 = ("VALOR DE BUZZDELAY: ");
int msgDelay = 800;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
  pinMode(potPin, INPUT);
}

void loop() {

  potVal = analogRead(potPin);
  //UTILIZAR LA FORMULA DE LA PENDIENTE DE LA LINEA
  buzzDelay = (9940. / 1023.) * potVal + 60;


  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(buzzDelay); //delay en microsegundos
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(buzzDelay);

  Serial.println(potVal);
  delay(msgDelay);
}
