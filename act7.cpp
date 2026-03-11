#include <Arduino.h>
#include <Servo.h>

Servo myServo;

int servoPin = 9;

void setup() {

  Serial.begin(9600);

  myServo.attach(servoPin);
  myServo.write(0);

  Serial.println("System Ready: Enter servo angle from 0 to 180.");
}

void loop() {

  if (Serial.available() > 0) {

    int userAngle = Serial.parseInt();

    // flush extra characters from serial
    while (Serial.available() > 0) {
      Serial.read();
    }

    if (userAngle >= 0 && userAngle <= 180) {

      myServo.write(userAngle);

      Serial.print("Angle set to: ");
      Serial.print(userAngle);
      Serial.println(" degrees");

    } 
    else {

      Serial.print("Error: ");
      Serial.print(userAngle);
      Serial.println(" is outside the allowed range (0-180).");

    }
  }

}