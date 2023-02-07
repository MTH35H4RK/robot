#include <SoftwareSerial.h>
SoftwareSerial BTserial(0, 1); // RX | TX
// LED PINS
int ledRight = 10;
int ledLeft = 13;

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
  analogWrite(ena, 200);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 200);
}
void right() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 0);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 200);

}
void left() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 200);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 0);
}
void back() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 200);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 200);
}
void FR() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 110);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 190);

}
void FL() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 190);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 105);
}
void BR() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 190);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 110);
}

void BL() {
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 105);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 200);
}
void ledoff() {
  digitalWrite(ledRight, LOW);
  digitalWrite(ledLeft, LOW);
}
void ledon() {
  digitalWrite(ledRight, HIGH);
  digitalWrite(ledLeft, HIGH);
}
void Ron() {
  digitalWrite(ledRight, HIGH);
  digitalWrite(ledLeft, LOW);
}
void Lon(){
  digitalWrite(ledRight, LOW);
      digitalWrite(ledLeft, HIGH);
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

  // setup pins for the LEDs
  pinMode(ledRight, OUTPUT);
  pinMode(ledLeft, OUTPUT);

  // set initial state for the motors and LEDs
  digitalWrite(ena, LOW);
  digitalWrite(enb, LOW);
  digitalWrite(ledRight, LOW);
  digitalWrite(ledLeft, LOW);
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
      ledon();
    } else if (command == 'L') {
      // turn left
      left();
      Lon();
    } else if (command == 'R') {
      // turn right
      right();
      Ron();
    } else if (command == 'G') {
      FL();
      Lon();
    } else if (command == 'I') {
      FR();
      Ron();
    } else if (command == 'J') {
      BL();
      Lon();
    } else if (command == 'H') {
      BR();
      Ron();
    } else if (command == 'S') {
      // stop
      digitalWrite(ena, LOW);
      digitalWrite(enb, LOW);
    }
  }
}
