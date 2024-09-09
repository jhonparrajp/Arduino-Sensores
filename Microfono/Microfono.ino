int mic = 7;
int led = 6;
int valor;
int estado;
int micAnalog=A0;

void setup() {
  pinMode(mic, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  pinMode(micAnalog,INPUT);
}

void loop() {
  Serial.println(valor);
  Serial.println(micAnalog);
  valor = digitalRead(mic);
  if(valor==HIGH){
    estado=digitalRead(led);
    digitalWrite(led,!estado);
    delay(500);
  }
}
