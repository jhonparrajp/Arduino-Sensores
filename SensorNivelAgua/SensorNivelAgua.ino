int sensor;
int sensorPin;
int dt=200;
int Led=7;

void setup() {
 Serial.begin(9600);
 pinMode(sensorPin,INPUT);
 pinMode(Led,OUTPUT);

}

void loop() {
  sensor=analogRead(sensorPin);
  Serial.println(sensor);
  delay(dt);
  if(sensor>0){
    digitalWrite(Led,1);
  }
  else{
    digitalWrite(Led,0);
  }
}
