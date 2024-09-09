int buzzPin = 9;
int ledPin = 10;
int dt = 500;
int number;
String msg1 = "Por favor introduce un numero";
int potPin = A0;
int potVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println();
  potVal = analogRead(potPin);
  Serial.println(potVal);

  while (potVal > 1000) {
    digitalWrite(buzzPin, HIGH);
    delay(dt);
    digitalWrite(buzzPin, LOW);
    digitalWrite(ledPin, HIGH);
    Serial.println(potVal);
    potVal = analogRead(potPin);
    delay(dt);
  }

  digitalWrite(buzzPin, LOW);
  digitalWrite(ledPin, LOW);



  //  number = Serial.parseInt();
  //
  //  if (number > 10) {
  //    digitalWrite(buzzPin, HIGH);
  //    delay(dt);
  //    digitalWrite(buzzPin, LOW);
  //  }
}
