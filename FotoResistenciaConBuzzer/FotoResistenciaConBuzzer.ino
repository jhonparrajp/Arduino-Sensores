//CLASE NUMERO 26 https://www.youtube.com/watch?v=mRsJYZmyXjY&list=PLyLh25DppBIe40j3VBAslnVfs4Pz-B3ZB&index=28&ab_channel=JohannPerezE
//CALCULAR PUNTO PENDIENTE PARA FOTORESISTENCIA

int lightVal;
float delayTime;
int lightPin = A5;
int buzzPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(lightPin, INPUT);
}

void loop() {

  lightVal = analogRead(lightPin);
  delayTime = (9. / 400.) * (lightVal - 300.) + 1;  //Se hallo con la ec de la pendiente
  Serial.println(lightVal);
  digitalWrite(buzzPin, HIGH);
  delay(delayTime);
  digitalWrite(buzzPin, LOW);
  delay(delayTime);
}
