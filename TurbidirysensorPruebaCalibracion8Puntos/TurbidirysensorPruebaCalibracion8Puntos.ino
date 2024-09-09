#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define Turbidity_sensor A0   
float Tension = 0.0;  
float NTU = 0.0;
float coeffs[8]; // Coeficientes para la interpolación polinómica de grado 7
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
  Serial.println("Coeficientes de la curva polinómica:");
  for (int i = 0; i < 8; i++) {
    Serial.print("a");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(coeffs[i]);
  }
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
  NTU = polyEvaluate(Tension); // Ajuste de NTU usando la calibración
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
  // Toma muestras de referencia y valores conocidos de NTU
  float voltages[8];
  float ntus[8] = {17.1, 49.2, 147, 208, 323, 355, 410, 495};
  
  for (int i = 0; i < 8; i++) {
    Serial.print("Coloca el sensor en la solución de referencia de ");
    Serial.print(ntus[i]);
    Serial.println(" NTU y presiona la tecla correspondiente ('1' a '8')...");
    waitForSpecificKey('1' + i);
    voltages[i] = readSensorAverage(Turbidity_sensor);
    Serial.print("Voltaje de referencia (");
    Serial.print(ntus[i]);
    Serial.print(" NTU): ");
    Serial.println(voltages[i]);
  }
  
  // Calcular los coeficientes de la curva polinómica
  polyFit(voltages, ntus, 8, coeffs);
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
  for (int i = 0; i < 500; i++) {
    total += analogRead(sensorPin) / 1024.0 * 5.0;
  }
  return total / 500.0;
}

float redondeo(float p_entera, int p_decimal) {  
  float multiplicador = pow(10.0f, p_decimal);  // Redondeo a 1 decimal  
  p_entera = round(p_entera * multiplicador) / multiplicador;  
  return p_entera;  
}

// Evaluar el polinomio en x
float polyEvaluate(float x) {
  float result = 0.0;
  for (int i = 7; i >= 0; i--) {
    result = result * x + coeffs[i];
  }
  return result;
}

// Ajuste polinómico de grado n
void polyFit(float x[], float y[], int n, float coeffs[]) {
  float a[n][n+1], ratio;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      a[i][j] = pow(x[i], j);
    }
  }
  for(int i = 0; i < n; i++) {
    a[i][n] = y[i];
  }
  
  for(int i = 0; i < n-1; i++) {
    for(int j = i+1; j < n; j++) {
      ratio = a[j][i] / a[i][i];
      for(int k = 0; k < n+1; k++) {
        a[j][k] -= ratio * a[i][k];
      }
    }
  }

  coeffs[n-1] = a[n-1][n] / a[n-1][n-1];
  
  for(int i = n-2; i >= 0; i--) {
    coeffs[i] = a[i][n];
    for(int j = i+1; j < n; j++) {
      coeffs[i] -= a[i][j] * coeffs[j];
    }
    coeffs[i] /= a[i][i];
  }
}
