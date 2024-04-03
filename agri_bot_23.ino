#include <AFMotor.h>
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(0, 1); // RX, TX


//Servo myservo;

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
int pos = 0;
int val;
int Speeed = 255; // Change this value between 0 to 255 for speed

void setup()
{
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A3, INPUT);
  bluetoothSerial.begin(9600);  //Set the baud rate to your Bluetooth module.
  //myservo.attach(9);  // attaches the servo on pin 9 to the servo object



}




void forward()
{

  motor2.setSpeed(Speeed);
  motor2.run(BACKWARD);
  motor4.setSpeed(Speeed);
  motor4.run(BACKWARD);
}

void back()
{

  motor2.setSpeed(Speeed);
  motor2.run(FORWARD);
  motor4.setSpeed(Speeed);
  motor4.run(FORWARD);
}

void left()
{


  motor2.setSpeed(Speeed);
  motor2.run(BACKWARD);
  motor4.setSpeed(Speeed);
  motor4.run(FORWARD);


}

void right()
{


  motor2.setSpeed(Speeed);
  motor2.run(FORWARD);
  motor4.setSpeed(Speeed);
  motor4.run(BACKWARD);

}

void drillpush() {
  digitalWrite(13, HIGH);
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  delay(1800);
  motor1.run(RELEASE);
  delay(2000);
  motor1.run(BACKWARD);
  delay(1800);
  motor1.run(RELEASE);
  digitalWrite(13, LOW);
}

void sensorpush()
{
  motor3.setSpeed(200);
  motor3.run(FORWARD);
  delay(2000);
  motor3.run(RELEASE);
  delay (2000);
  int value = analogRead(A3);
  Serial.println(value);
  /*if (value > 950) {
    digitalWrite(2, LOW);
    } else {
    digitalWrite(2, HIGH);
    }*/
  motor3.run(BACKWARD);
  delay(2000);
  motor3.run(RELEASE);

}
void automatic()
{
  digitalWrite(13, HIGH);
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  delay(1800);
  motor1.run(RELEASE);
  delay(2000);
  motor1.run(BACKWARD);
  delay(1800);
  motor1.run(RELEASE);
  digitalWrite(13, LOW);
  delay(1000);
  //for(pos = 0; pos <= 10; pos += 1) { // goes from 0 degrees to 180 degrees
  // in steps of 1 degree
  //myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //delay(1);                       // waits 15 ms for the servo to reach the position
  //}
  //for (pos = 10; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  // myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //delay(1);                       // waits 15 ms for the servo to re
  //}
  motor3.setSpeed(200);
  motor3.run(FORWARD);
  delay(2000);
  motor3.run(RELEASE);
  delay (2000);
  int value = analogRead(A3);
  Serial.println(value);
  /*if (value > 950) {
    digitalWrite(2, LOW);
    } else {
    digitalWrite(2, HIGH);
    }*/
  motor3.run(BACKWARD);
  delay(2000);
  motor3.run(RELEASE);
  delay(2000);
  motor2.setSpeed(200);
  motor4.setSpeed(200);
  motor2.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(2000);
  motor2.run(RELEASE);
  motor4.run(RELEASE);

}

void idk() {
  //for(pos = 0; pos <= 10; pos += 1) { // goes from 0 degrees to 180 degrees
  // in steps of 1 degree
  // myservo.write(pos);              // tell servo to go to position in variable 'pos'
  // delay(1);                       // waits 15 ms for the servo to reach the position
  //}
  //for (pos = 10; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  // myservo.write(pos);              // tell servo to go to position in variable 'pos'
  // delay(1);                       // waits 15 ms for the servo to re

}






void Stop()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}

void loop()
{
  if (Serial.available() > 0) {
    val = Serial.read();



    if (val == 'F') {
      forward();
    }

    if (val == 'B') {
      back();
    }

    if (val == 'L') {
      left();
    }

    if (val == 'R') {
      right();
    }
    if (val == 'I') {
      drillpush();
    } 

    if (val == 'J') {
      sensorpush();
    }

    if (val == 'K') {
      automatic();
    }

    if (val == 'M') {
      //          idk();
    }
    if (val == 'T') {
      Stop();
    }
  }
}
