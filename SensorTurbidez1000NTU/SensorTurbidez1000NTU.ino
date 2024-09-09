
// Programa...: Calibracion-Turbidez   
// Autor......: jhon parra 
// Descripción: Calibración del sensor de turbidez y ajuste de lecturas a un rango máximo de 100 NTU  
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define Turbidity_sensor A0   
float Tension = 0.0;  
float NTU = 0.0;
float CalibSlope = 1.0; // Pendiente de calibración
float CalibIntercept = 0.0; // Intercepto de calibración
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {   
  Serial.begin(115200); // Velocidad de comunicación  
  Serial.println("Calibración del sensor de turbidez");
  Serial.println("===================================");
  Serial.println(" ");

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Turbidez");
  delay(2000);
  // Fase de calibración
  Serial.println("Fase de calibración:");
  calibrateSensor();
  
  Serial.println("Calibración completa.");
  Serial.print("Pendiente de calibración: ");
  Serial.println(CalibSlope);
  Serial.print("Intercepto de calibración: ");
  Serial.println(CalibIntercept);
  Serial.println(" ");
  
  Serial.println("Lectura del sensor de turbidez y expresión del resultado en unidades nefelométricas");  
  Serial.println("===================================================================================");  
  Serial.println(" ");  
  Serial.println("Tension\tNTU");   
  Serial.println("-------\t---");  
}

void loop() {  
  Tension = readSensorAverage(Turbidity_sensor);  
  Tension = redondeo(Tension, 1);  
  NTU = CalibSlope * Tension + CalibIntercept; // Ajuste de NTU usando la calibración
  if (NTU < 0) { NTU = 0; } // Ajuste para evitar valores negativos
  
  // Envío de valores y textos al terminal serie  
  Serial.print(Tension);  
  Serial.print(" V");  
  Serial.print("\t");  
  Serial.print(NTU);  
  Serial.println(" NTU");  
  delay(2000);  
}  

void calibrateSensor() {
  // Toma muestras de referencia
  float refVoltageLow = 0.0; // Voltaje de referencia para NTU bajo (0 NTU)
  float refNTULow = 1.0;     // NTU bajo (0 NTU)
  float refVoltageHigh = 0.0; // Voltaje de referencia para NTU alto (100 NTU)
  float refNTUHigh = 500.0;   // NTU alto (100 NTU)
  
  Serial.println("Coloca el sensor en la solución de referencia de 1 NTU y presiona la tecla 'L'...");
  waitForSpecificKey('L');
  refVoltageLow = readSensorAverage(Turbidity_sensor);
  Serial.print("Voltaje de referencia (1 NTU): ");
  Serial.println(refVoltageLow);
  
  Serial.println("Coloca el sensor en la solución de referencia de 100 NTU y presiona la tecla 'H'...");
  waitForSpecificKey('H');
  refVoltageHigh = readSensorAverage(Turbidity_sensor);
  Serial.print("Voltaje de referencia (500 NTU): ");
  Serial.println(refVoltageHigh);
  
  // Calcula la pendiente y el intercepto para la calibración
  CalibSlope = (refNTUHigh - refNTULow) / (refVoltageHigh - refVoltageLow);
  CalibIntercept = refNTULow - (CalibSlope * refVoltageLow);
}

void waitForSpecificKey(char key) {
  while (true) {
    if (Serial.available() > 0) {
      char input = Serial.read();
      if (input == key) {
        break;
      }
    }
  }
}

float readSensorAverage(int sensorPin) {
  float total = 0.0;
  for (int i = 0; i < 1000; i++) {
    total += analogRead(sensorPin) / 1024.0 * 5.0;
  }
  return total / 1000;
}

float redondeo(float p_entera, int p_decimal) {  
  float multiplicador = pow(10.0f, p_decimal);  // Redondeo a 1 decimal  
  p_entera = round(p_entera * multiplicador) / multiplicador;  
  return p_entera;  
}


