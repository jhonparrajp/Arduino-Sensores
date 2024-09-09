int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
 // Configurar el pin como salida
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
// Encender el LED
  digitalWrite(ledPin, HIGH);
  delay(300); // Esperar 1 segundo

  // Apagar el LED
  digitalWrite(ledPin, LOW);
  delay(300); // Esperar 1 segundo

}
