#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Zeno.h>

SoftwareSerial EEBlue(10, 11);

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *motorA = AFMS.getMotor(1);
Adafruit_DCMotor *motorB = AFMS.getMotor(2);
Adafruit_DCMotor *motorC = AFMS.getMotor(3);

void setup() {
  AFMS.begin();
  
  motorA->setSpeed(150);
  motorA->run(FORWARD);
  
  motorB->setSpeed(150);
  motorB->run(FORWARD);

  motorC->setSpeed(150);
  motorC->run(FORWARD);

  motorA->run(RELEASE);
  motorB->run(RELEASE);
  motorC->run(RELEASE);
  delay(10000);
  Serial.begin(9600);
  Serial.println("ready");

}

void moveAtAngle(float angle, int speed) {
  
  int speedA = round(speed * cos((150 - angle) * (M_PI / 180)));
  int speedB = round(speed * cos((30 - angle) * (M_PI / 180)));
  int speedC = round(speed * cos((270 - angle) * (M_PI / 180)));

  if(speedA < 0) {
    motorA -> run(BACKWARD);
    motorA -> setSpeed(-1 * speedA);
  } else if (speedA == 0) {
    motorA -> run(RELEASE);
  } else {
    motorA -> run(FORWARD);
    motorA -> setSpeed(speedA);
  }

  if(speedB < 0) {
    motorB -> run(BACKWARD);
    motorB -> setSpeed(-1 * speedB);
  } else if (speedB == 0) {
    motorB -> run(RELEASE);
  } else {
    motorB -> run(FORWARD);
    motorB -> setSpeed(speedB);
  }

  if(speedC < 0) {
    motorC -> run(BACKWARD);
    motorC -> setSpeed(-1 * speedC);
  } else if (speedC == 0) {
    motorC -> run(RELEASE);
  } else {
    motorC -> run(FORWARD);
    motorC -> setSpeed(speedC);
  }
  
}

void loop() {

  if(!Serial.available() > 0) {
    return;
  }
  
  String readString = "";
  while (Serial.available() > 0) {
    delay(3);
    char c = Serial.read();
    readString += c;
  }
  
  Serial.println(readString);
    if (readString.length() > 0) {
        Serial.println(readString);
        
        if (readString == "F") {
          moveAtAngle(0.0, 150);
        }

        if (readString == "S") {
          moveAtAngle(0.0, 0);
        }

        if (readString == "L") {
          moveAtAngle(-90.0, 150);
        }

        if (readString == "R") {
          moveAtAngle(90.0, 150);
        }

        if (readString == "B") {
          motorA -> run(FORWARD);
          motorA -> setSpeed(150);
          motorB -> run(FORWARD);
          motorB -> setSpeed(150);
          motorC -> run(FORWARD);
          motorC -> setSpeed(150);

          delay(375);
          moveAtAngle(0.0, 0);
        }

        readString = "";  
   }
}
   
