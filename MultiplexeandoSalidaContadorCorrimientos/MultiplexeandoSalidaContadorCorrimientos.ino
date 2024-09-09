//CLASE 38 https://www.youtube.com/watch?v=-pvTlcFQ2Wg&list=PLyLh25DppBIe40j3VBAslnVfs4Pz-B3ZB&index=39&ab_channel=JohannPerezE
//MIRAR EL DATASHEET DE 74HC595 PARA LAS CONEXIONES
int lachtPin = 8;
int clockPin = 13;
int dataPin = 12;
byte myByte = 0b00000111;
int dt = 500;


void setup() {
  Serial.begin(96100);
  pinMode(lachtPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  digitalWrite(lachtPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte);
  digitalWrite(lachtPin, HIGH);
  Serial.println(myByte, BIN);
  delay(dt);
  //myByte=(myByte/2); //corrimiento a la derecha
  //myByte = (myByte * 2); //corrimiento a la izquierda
  // myByte=myByte + 1; //CONTADOR
  //myByte = (myByte * 128+myByte/2);//Circular shift a la derecha
  myByte = (myByte /128 + myByte * 2);  //Circular shift a la izquierda
}