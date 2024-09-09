#include <IRremote.hpp>
//Control
//CH- =69 CH=70 CH+=71
//prev=68 next=64 play=67
//vol-=7 vol+=21 EQ=9
//0=22 100+=25 200+=13
//1=12 2=24 3=94
//4=8 5=28 6=90
//7=66 8=82 9=74


int IRpin = 9;
int bluePin=10;
int greenPin=6;
int redPin=3;
int dt=1000;
int stateb=0;
int stateg=0;
int stater=0;
void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IRpin);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
}

void loop() {
  while (IrReceiver.decode() == 0) {
  }
  int comand = IrReceiver.decodedIRData.command;
  Serial.println(comand);
  delay(500);
  IrReceiver.resume();

  if(comand==9){
    if(stateb==0){
      stateb=1;
    }
    else{
      stateb=0;
    }
  }
  if(comand==67){
    if(stateg==0){
      stateg=1;
    }
    else{
      stateg=0;
    }
  }
  if(comand==71){
    if(stater==0){
      stater=1;
    }
    else{
      stater=0;
    }
  }
digitalWrite(redPin,stater);
digitalWrite(greenPin,stateg);
digitalWrite(bluePin,stateb);
}
