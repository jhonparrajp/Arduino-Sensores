//CLASE 32 https://www.youtube.com/watch?v=mIhkmMHG84w&list=PLyLh25DppBIe40j3VBAslnVfs4Pz-B3ZB&index=34&ab_channel=JohannPerezE
//UTILIZAR UN BOTON PULL SIN RESISTENCIAS
//CONECTAR UNA DE LAS PATAS A GND Y LA OTRA A UN PIN DIGITAL

int pinButton = 8;
int buttonVal;


void setup() {
  Serial.begin(9600);
  pinMode(pinButton, INPUT_PULLUP); //para usar el boton sin resistencia como pull up
 
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal = digitalRead(pinButton);
  Serial.println(buttonVal);
}
