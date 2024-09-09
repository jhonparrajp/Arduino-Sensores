int blueLed =9;
int brightness =20;
int brightness1 =50;
int brightness2 =150;
int dt =2500;

void setup() {
  // put your setup code here, to run once:
pinMode(blueLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(blueLed,brightness);
delay(dt);
analogWrite(blueLed,brightness1);
delay(dt);
analogWrite(blueLed,brightness2);
delay(dt);
}
