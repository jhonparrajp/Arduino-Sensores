int ledPin1 = 10;
int ledPin2 = 8;
int dt = 500;
int yellow = 3;
int red = 5;
int i;


void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

}

void loop() {

  for (i = 0; i < yellow; i++) {
    digitalWrite(ledPin1, HIGH);
    delay(dt);
    digitalWrite(ledPin1, LOW);
    delay(dt);
  }

  for (i = 0; i < red; i++) {
    digitalWrite(ledPin2, HIGH);
    delay(dt);
    digitalWrite(ledPin2, LOW);
    delay(dt);
  }




}
