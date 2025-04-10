#include <Servo.h>

const int switchPin = 5;  // Pin reading the cardboard switch state
const int servoPin = 4;   // Servo motor control pin

Servo myServo;

void setup() {
    Serial.begin(9600);  // Initialize serial communication
    pinMode(switchPin, INPUT_PULLUP);  // Use internal pull-up resistor
    myServo.attach(servoPin);   // Attach servo
}

void loop() {
    int switchState = digitalRead(switchPin);  // Read the switch input
    Serial.print("Switch State: ");
    Serial.println(switchState);  // Debugging output

    if (switchState == HIGH) {  // Adjusted for INPUT_PULLUP (LOW when ON)
        Serial.println("Switch ON");
        myServo.write(0);  // Rotate to 0 degrees
        delay(500);        // Wait 500ms
        myServo.write(180); // Rotate to 180 degrees
        delay(500);        // Wait 500ms
    } else {
        Serial.println("Switch OFF");
        myServo.write(0);  // Neutral position
    }
}