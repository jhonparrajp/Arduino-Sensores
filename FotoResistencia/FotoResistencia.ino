//PARA EL CIRCUITO CON FOTORESISTENCIA
//SE USA UN DIVISOR DE VOLTAJE PARA MEDIR EL CAMBIO EN LA RESISTENCIA
//USAR UNA RESISTENCIA DE UN VALOR PROXIMO A LA MITAD DE EL VALOR MAXIMO DE LA FOTORESISTENCIA
//LA PATA QUE COMPARTE LA FOTO RESISTENCIA CON LA RESISTENCIA
//SE MANDA A UN PIN ANALOGO
//  A MAYOR LUZ ,MENOR RESISTENCIA , MAYOR CORRIENTE
//A MENOR LUZ , MAYOR RESISTENCIA ,MENOR CORRIENTE

int lightPin = A5;
int lightVal;
int dt = 200;
int gPin = 10;
int rPin = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  pinMode(gPin, OUTPUT);
  pinMode(rPin, OUTPUT);
}

void loop() {
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(dt);

  if (lightVal < 700) {
    digitalWrite(gPin, 1);
    digitalWrite(rPin, 0);
  }
  else if (lightVal >= 700) {
    digitalWrite(gPin, 0);
    digitalWrite(rPin, 1);
  }

}
