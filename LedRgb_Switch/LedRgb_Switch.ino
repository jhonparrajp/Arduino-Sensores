int colorLed;
String msg1 = "Escribe el color que deseas";
String msg2 = " 1-rojo, 2-azul, 3-verde 4-Morado 5-amarillo 6-turquesa 7-naranjado";
int red = 11;
int green = 9;
int blue = 10;
int dt = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // Primero preguntamos
  Serial.println();
  Serial.println(msg1);
  Serial.println(msg2);
  //Luego esperamos , haciendo uso de un ciclo while
  //mientras no haya nada en el monitor seral , esperar
  while (Serial.available() == 0) {

  }
  colorLed = Serial.parseInt(); //Leemos el valor de nuestro nombre y lo guardamos en la variable

  switch (colorLed) {
    case 1:
      digitalWrite(red, HIGH);
      digitalWrite(blue, LOW);
      digitalWrite(green, LOW);
      break;

    case 2:
      digitalWrite(blue, HIGH);
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      break;

    case 3:
      digitalWrite(green, HIGH);
      digitalWrite(blue, LOW);
      digitalWrite(red, LOW);
      break;

    case 4:
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
      digitalWrite(red, HIGH);
      break;

    case 5:
      analogWrite(green, 150);
      analogWrite(blue, 0);
      analogWrite(red, 255);
      break;

    case 6:
      analogWrite(green, 255);
      analogWrite(blue, 150);
      analogWrite(red, 0);
      break;

    case 7:
      analogWrite(green, 100);
      analogWrite(blue, 0);
      analogWrite(red, 255);
      break;

    default:
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(red, LOW);
      Serial.println("EL VALOR NO EXISTE");
      Serial.println("POR FAVOR INTENTA DE NUEVO");
  }


  Serial.print(colorLed);

}
