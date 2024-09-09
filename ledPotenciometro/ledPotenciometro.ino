int ledPin = 4;
int potPin = A0;
int potVal;
int dt = 500;
int light;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.println(potVal);
  Serial.println(light);
  //Funcion map sirve para convertir parametro, la funcion requiere de 5 parametros
  //variable donde estaran los datos , y de que rango a que rango se quiere convertir
  light = map(potVal,0,1023,0,255);
  analogWrite(ledPin,light);
  delay(dt);
}
