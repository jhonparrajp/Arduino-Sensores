String myName;
String msg1 = "Escribe tu nombre";
String msg2 = "Hola :";
String msg3 = ", Bienvenido a el mejor proyecto de arduino";

void setup() {
  // incializamos nuestro monitor en serie con un baudreid de 115200
  Serial.begin(115200);
}

void loop() {
  // Primero preguntamos
  Serial.println();
  Serial.println(msg1);
  //Luego esperamos , haciendo uso de un ciclo while
  //mientras no haya nada en el monitor seral , esperar
  while(Serial.available() == 0){
    
  }
  myName= Serial.readString(); //Leemos el valor de nuestro nombre y lo guardamos en la variable
  Serial.print(msg2);
  Serial.print(myName);
  Serial.println(msg3);
}
