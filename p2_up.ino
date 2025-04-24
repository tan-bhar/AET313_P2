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

void loop() {
  // Interaction 1: 360 servo *** MODIFIED. USER MOVES MANUALLY INSTEAD (WHICH IS NEW INTERACTION 1) ***
  if (digitalRead(switch1) == HIGH) {
    servo360.write(86);
    Serial.println("on1");
  } else {
    servo360.write(93);
    Serial.println("off1");
  }

  // Interaction 2: house flap
  if (digitalRead(switch2) == HIGH) {
    houseFlap.write(140);
    Serial.println("on2");
  } else {
    houseFlap.write(20);
    Serial.println("off2");
  }

  // Interaction 3: paradise falls (servo + melody)
  if (digitalRead(switch3) == HIGH) {
    paradise.write(5);
    playUpMelody(); // Play melody here now
    Serial.println("on3");
  } else {
    paradise.write(80);
    noTone(buzzerPin); // No melody if switch is off
    Serial.println("off3");
  }

  // Interaction 4: dug flapping (servo only)
  if (digitalRead(switch4) == HIGH) {
    dug.write(0);
    Serial.println("on4");
  } else {
    dug.write(180);
    Serial.println("off4");
  }

    // Interaction 5: up melody plays at the end
void playUpMelody() {
  int melody[] = {392, 494, 392, 370, 370, 392, 494, 392, 330, 330, 392, 330, 294, 330, 494, 440, 330, 494, 440, 392, 330}; 
  int duration = 400; 

  for (int i = 0; i < 22; i++) {
    tone(buzzerPin, melody[i], duration);
    delay(duration);
    noTone(buzzerPin);  // Make sure the buzzer stops between notes
    delay(.01);          // A short silence between notes to avoid overlap
  }
  
  noTone(buzzerPin);  // Final silence to stop any lingering signal
}
}




  