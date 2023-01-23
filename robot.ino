#include <SoftwareSerial.h>
SoftwareSerial BTserial(0, 1); // RX | TX

// MOTOR1 PINS
int ena = 9;
int in1 = 8;
int in2 = 7;
int in3 = 6;
int in4 = 5;
int enb = 3;

void forward() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 150);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 155);
}
void right() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 30);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 120);

}
void left() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 120);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 30);
}
void back() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 120);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 118);
}
void FR() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 95);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 150);

}
void FL() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 140);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 90);
}
void BR() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 150);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 95);
}

void BL() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 90);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 140);
}
void setup() {
  // setup serial communication with the HC-05 module
  BTserial.begin(9600);

  // setup pins for the motor driver
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT);

  // set initial state for the motors
  digitalWrite(ena, LOW);
  digitalWrite(enb, LOW);
}

void loop() {
  // check if there is data available to read
  if (BTserial.available()) {
    // read the incoming data
    char command = BTserial.read();

    // check the command and control the robot accordingly
    if (command == 'F') {
      // move forward
      forward();
    } else if (command == 'B') {
      // move backward
      back();
    } else if (command == 'L') {
      // turn left
      left();
    } else if (command == 'R') {
      // turn right
      right();
    } else if (command == 'G') {
      FL();
    } else if (command == 'I') {
      FR();
    } else if (command == 'J') {
      BL();
    } else if (command == 'H') {
      BR();
    } else if (command == 'S') {
      // stop
      digitalWrite(ena, LOW);
      digitalWrite(enb, LOW);
    }
  }
}
