#include <Servo.h>

const int servo360Pin = 13;
const int houseFlapPin = 11;
const int paradisePin = 9;
const int dugPin = 7;
const int switch2 = 12;
const int switch1 = 10;
const int switch3 = 8;
const int switch4 = 5;
const int buzzerPin = 2; // Buzzer pin

Servo servo360;
Servo houseFlap;
Servo paradise;
Servo dug;

void setup() {
  servo360.attach(servo360Pin);
  houseFlap.attach(houseFlapPin);
  paradise.attach(paradisePin);
  dug.attach(dugPin);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT); 
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

