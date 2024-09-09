// CLASE 33 https://www.youtube.com/watch?v=MzW4e_kc4FM&list=PLyLh25DppBIe40j3VBAslnVfs4Pz-B3ZB&index=35&ab_channel=JohannPerezE
//CONEXION DE JOYSTICK
//VRx = Resistencia variable en eje x -VRy =eje y ,SW= boton
//los vr van a pines de ADC y el boton a un pin digital

int xPin = A0;
int yPin = A1;
int buttonPin = 7;
int buzzerPin = 13;
int xVal;
int yVal;
int buttonVal;
int dt=200;

void setup() {
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  buttonVal = digitalRead(buttonPin);
  Serial.print("Valor de X = ");
  Serial.print(xVal);
  Serial.print(" - Valor de Y = ");
  Serial.print(yVal);
  Serial.print(" - Valor de Boton = ");
  Serial.println(buttonVal);
  delay(dt);
  if(buttonVal==0){
    digitalWrite(buzzerPin,1);
    delay(dt);
    digitalWrite(buzzerPin,0);
  }
  else{
    digitalWrite(buzzerPin,0);

  }
}
