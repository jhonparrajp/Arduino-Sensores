
float area;
float Pi = 3.1415;
int dt = 500;
int rad =3;
String mensaje1 = "El area de un circulo con radio de ";
String mensaje2 = ( " es de :" ); 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
float area = Pi*rad*rad;

Serial.print( mensaje1 );
Serial.print(rad);
Serial.print( mensaje2);
Serial.println(area);

delay(dt);
rad++;
}
