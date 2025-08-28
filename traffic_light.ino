#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


int clgreen = 11;
int clyellow = 12;
int clred = 13;
int pdred = 10;
int pdgreen = 9;
int button = 5;
int crossTime = 5000;
unsigned long changeTime;
#define BUZZER 8

SoftwareSerial mySoftwareSerial(6, 3);  // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(clgreen, OUTPUT);
  pinMode(clyellow, OUTPUT);
  pinMode(clred, OUTPUT);
  pinMode(pdgreen, OUTPUT);
  pinMode(pdred, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(clgreen, HIGH);
  digitalWrite(pdred, HIGH);
  mySoftwareSerial.begin(9600);
  // Initialize Arduino serial
  Serial.begin(115200);
  // Check if the module is responding and if the SD card is found
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini"));
  Serial.println(F("Initializing DFPlayer module ... Wait!"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Not initialized:"));
    Serial.println(F("1. Check the DFPlayer Mini connections"));
    Serial.println(F("2. Insert an SD card"));
    while (true)
      ;
  }
  Serial.println();
  Serial.println(F("DFPlayer Mini module initialized!"));
  // Initial settings
  myDFPlayer.setTimeOut(500);  // Serial timeout 500ms
  }

void loop() {
  // put your main code here, to run repeatedly
  int state = digitalRead(button);
  if(state == HIGH && (millis() - changeTime) > 5000){
    change_light();
  }
}

void change_light(){
  carlightchange1();
  delay(1000);
  digitalWrite(pdred, LOW);
  digitalWrite(pdgreen, HIGH);
  sound();
  myDFPlayer.play(1);
  delay(4000);
  myDFPlayer.stop();
  delay(1000);
  delay(crossTime);
  pedestrian_hurry();
  delay(1000);
  digitalWrite(pdgreen, LOW);
  digitalWrite(pdred, HIGH);
  sound();
  myDFPlayer.play(3);
  delay(2000);
  myDFPlayer.stop();
  delay(2000);
  carlightchange2();
  changeTime = millis();
}

void carlightchange1(){
  digitalWrite(clgreen, LOW);
  digitalWrite(clyellow, HIGH);
  sound();
  delay(1500);
  digitalWrite(clyellow, LOW);
  digitalWrite(clred, HIGH);
  sound();
}

void pedestrian_hurry(){
  for (int i = 0; i < 5; i++){
    digitalWrite(pdgreen, LOW);
    delay(500);
    digitalWrite(pdgreen, HIGH);
    sound();
  }
}

void carlightchange2(){
  digitalWrite(clred, LOW);
  digitalWrite(clyellow, HIGH);
  sound();
  delay(1500);
  digitalWrite(clyellow, LOW);
  digitalWrite(clgreen, HIGH);
  sound();
}

void sound(){
  tone(BUZZER, 5000);
  delay(100);
  noTone(BUZZER);
}