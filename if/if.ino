float V2;
int readVal;
int analogPin = A2;
int dt=500;
int ledPin = 10;
int ledPin2 = 11;
int ledPin3 = 12;


void setup() {
  Serial.begin(9600);
  pinMode(analogPin,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);

}
//OPERADORES
// < - > - <= - >= - == - != - && (y) - || (o)
void loop() {
 readVal = analogRead(analogPin);
 V2 = (5.*readVal)/1023.;
if (V2<=2){
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin,LOW);
  digitalWrite(ledPin2,LOW);
}
if(V2>2.0 && V2<4.0){
   digitalWrite(ledPin2,HIGH);
   digitalWrite(ledPin,LOW);
  digitalWrite(ledPin3,LOW);
}
if(V2>4){
   digitalWrite(ledPin,HIGH);
     digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
}
 
 Serial.println(V2);
 delay(dt);

}
