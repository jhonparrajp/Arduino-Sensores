//utilizar el atmega328 old bootloadder
//para subir el programa

int led1 =5;
int led2 =6;
int led3 =7;
int led4=9;
int led5 =10;
int led6 =11;
int led7=12;
int led8=13;
int dt=500;


void setup() {
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(led4,OUTPUT);
 pinMode(led5,OUTPUT);
 pinMode(led6,OUTPUT);
 pinMode(led7,OUTPUT);
 pinMode(led8,OUTPUT);
 Serial.begin(9600);
}

void loop() {
 digitalWrite(led1,1);
 digitalWrite(led4,1);
 digitalWrite(led2,0);
 digitalWrite(led3,0);
 digitalWrite(led5,1);
 digitalWrite(led6,1);
 digitalWrite(led7,1);
 digitalWrite(led8,1);
delay(dt);
 digitalWrite(led1,0);
 digitalWrite(led2,1);
 digitalWrite(led3,0);
 digitalWrite(led4,1);
 delay(dt);
 digitalWrite(led1,0);
 digitalWrite(led2,0);
 digitalWrite(led3,1);
 digitalWrite(led4,1);
 delay(dt);
  digitalWrite(led1,0);
 digitalWrite(led4,0);
 digitalWrite(led2,1);
 digitalWrite(led3,1);
 digitalWrite(led5,0);
 digitalWrite(led6,0);
 digitalWrite(led7,0);
 digitalWrite(led8,0);
delay(dt);

 Serial.print(led1);
}
