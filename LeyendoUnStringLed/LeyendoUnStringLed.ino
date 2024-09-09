int greenPin = 9;
int redPin = 8;
int bluePin =10;
String ledColor;
String msg1 = "Escribe un color de led";


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(greenPin,OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(bluePin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println();
Serial.println(msg1);
while (Serial.available() == 0){
  
}

ledColor = Serial.readString();

if (ledColor == "verde" || ledColor == "VERDE"){
  digitalWrite(greenPin,HIGH);
  digitalWrite(redPin,LOW);
  digitalWrite(bluePin,LOW);
  
}
if (ledColor == "rojo" || ledColor == "ROJO"){
  digitalWrite(greenPin,LOW);
  digitalWrite(redPin,HIGH);
  digitalWrite(bluePin,LOW);
  
}
if (ledColor == "azul" || ledColor == "AZUL"){
  digitalWrite(greenPin,LOW);
  digitalWrite(redPin,LOW);
  digitalWrite(bluePin,HIGH);
  
}

}
