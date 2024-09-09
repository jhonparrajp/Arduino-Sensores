int led=2;
int ledAnterior=4;

void setup() {
  
  // put your setup code here, to run once:
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (8, OUTPUT);

}

void loop() {
 
  //Detectar si llega a 10
  if(led==10) { led=2;}

  //encender el led
  digitalWrite(led, HIGH);

  //Apagar el led
  digitalWrite(ledAnterior,LOW);

  //guardar el valor de el led anterior
   ledAnterior= led;

  //sumamos 2 a la variable led
  led +=2;

  delay(100);

 
}
