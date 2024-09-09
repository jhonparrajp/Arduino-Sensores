int blinkTimes;
String msg1 = " Por favor ingresa el numero de parpadeos: ";
int i;
int ledPin=10;
int dt=300;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println();
  Serial.println(msg1);
  while (Serial.available() == 0 ) {

  }
  blinkTimes = Serial.parseInt();
  
  for (i = 1 ; i <=blinkTimes  ; i++) {
  digitalWrite(ledPin,HIGH);
  delay(dt);
  digitalWrite(ledPin,LOW);
  delay(dt);
  }
}
