int lachtPin = 8;
int clockPin = 13;
int dataPin = 12;
byte myByte1 = 0b01010101;
byte myByte2 = 0b10101010;
int dt = 250;


void setup() {
  Serial.begin(96100);
  pinMode(lachtPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  digitalWrite(lachtPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte1);
  digitalWrite(lachtPin, HIGH);
  delay(dt);
  digitalWrite(lachtPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte2);
  digitalWrite(lachtPin, HIGH);
  delay(dt);
}
