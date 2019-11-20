/*This is part of the code; // Everything after these slashes is a comment and not part of the code

/*
 * 
 * Everything in this block is commented out
 * 
 */

#define INFRAREDONE 2
#define INFRAREDTWO 3
#define ULTRASONIC_TRIG 4
#define ULTRASONIC_ECHO 5
#define LASER_DIODE 6
#define MOTOR_ONE_A 2
#define MOTOR_ONE_B 3
#define MOTOR_TWO_A 5
#define MOTOR_TWO_B 4
#define BUZZER 7
#define LED ?
#define TURRET_SERVO 8

//move backwards
void moveBackwards() {
  //this is where the code for moving backwards will go.
digitalWrite(MOTOR_ONE_A, HIGH);
digitalWrite(MOTOR_ONE_B, LOW);
digitalWrite(MOTOR_TWO_A, HIGH);
digitalWrite(MOTOR_TWO_B, LOW);

  
}

//move forwards
void moveForwards() {
digitalWrite(MOTOR_ONE_A, LOW);    // Write to input M1A Low
digitalWrite(MOTOR_ONE_B, HIGH);
digitalWrite(MOTOR_TWO_A, LOW);
digitalWrite(MOTOR_TWO_B, HIGH);
}

//Turn left
void turnLeft() {
 digitalWrite(MOTOR_ONE_A, LOW);
digitalWrite(MOTOR_ONE_B, HIGH);
digitalWrite(MOTOR_TWO_A, HIGH);
digitalWrite(MOTOR_TWO_B, LOW);
}

//turn right
void turnRight() {
digitalWrite(MOTOR_ONE_A, HIGH);
digitalWrite(MOTOR_ONE_B, LOW);
digitalWrite(MOTOR_TWO_A, LOW);
digitalWrite(MOTOR_TWO_B, HIGH);
}

void allStop() {
digitalWrite(MOTOR_ONE_A, LOW);
digitalWrite(MOTOR_ONE_B, LOW);
digitalWrite(MOTOR_TWO_A, LOW);
digitalWrite(MOTOR_TWO_B, LOW);
}

//detect infrared

void detectInfrared() {
  
}

//detect echo
void detectEcho() {

}
//fire ze laser!!!

void laserFire() {
  // Everything in these squiggly brackets is
  // part of the laserFire function code block

}

int variable1 = 0;





void setup() {
  pinMode(MOTOR_ONE_A, OUTPUT);
  pinMode(MOTOR_ONE_B, OUTPUT);
  pinMode(MOTOR_TWO_A, OUTPUT);
  pinMode(MOTOR_TWO_B, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  moveForwards();
  delay(1000);
  allStop();
  delay(500);
  moveBackwards();
  delay(1000);
 allStop();
  delay(500);
  turnRight();
  delay(1000);
   allStop();
  delay(500);
  turnLeft();
  delay(1000);
     allStop();
  delay(500);
}
