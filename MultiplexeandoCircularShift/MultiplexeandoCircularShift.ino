//CLASE 38 https://www.youtube.com/watch?v=-pvTlcFQ2Wg&list=PLyLh25DppBIe40j3VBAslnVfs4Pz-B3ZB&index=39&ab_channel=JohannPerezE
//MIRAR EL DATASHEET DE 74HC595 PARA LAS CONEXIONES
int lachtPin = 8;
int clockPin = 13;
int dataPin = 12;
             //ABCDEFGX
byte myByte = 0b11110010;//3
//CREAMOS UN ARRAY PARA GUARDAR LOS NUMEROS EN BINARIO
byte numbers[]={
  0b11111100,//0
  0b01100000,//1
  0b11011010,//2
  0b11110010,//3
  0b01100110,//4
  0b10110110,//5
  0b10111110,//6
  0b11100000,//7
  0b11111110,//8
  0b11110110,//9
};
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
  //myByte = (myByte /128 + myByte * 2);  //Circular shift a la izquierda
  // myByte = 255-myByte; //bipflick
}