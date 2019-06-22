#include <HCSR04.h>  //ultrasonic sensor library
#include <Servo.h>   //servo library


#define PIEZO 2      //piezo pin, use tone(
#define TURRET 9     //turret servo control pin 
#define LEDW 4       //white LED pin 
#define LEDR 12      //red LED pin 
#define LEDG 15      //green LED pin 
#define LASREC 7     //laser receiver module pin
#define ULTRAT 8     //ultrasonic sensor trigger pin
#define ULTRAE 13    //ultrasonic sensor echo pin
#define MOTONEA 5    //motor one A control pin
#define MOTONEB 6    //motor one B control pin
#define MOTTWOA 3    //motor two A control pin
#define MOTTWOB 11   //motor two B control pin
#define LASEROUT 14  //laser cannon control pin

#define interval_laser 499     // define values for intervals in millis() functions
#define interval_beep 2999
#define interval_beeplength 15
#define interval_echo 175
//#define interval_rotate 1000

#define MOTONESPD 205  // change these two numbers to calibrate your motors
#define MOTTWOSPD 165  // this will let your tank drive in a straight line

unsigned long time_fire = 0;     // These values hold the time in millis()
unsigned long time_beeps = 0;    // for the delay between/during events
unsigned long time_echo = 0;
unsigned long time_move = 0;
unsigned long time_rotate = 0;
unsigned long interval_rotate = 0;
int turn_direction = 1;
int rotate = 0;
boolean laser = 0;
boolean piezo = 0;


UltraSonicDistanceSensor distanceSensor(ULTRAT, ULTRAE);  // Initialize the ultrasonic sensor
float range = 0;             // variable to store ultrasonic range

Servo myservo;               // create the servo object
int pos = 25;                // declare variable for servo position
int increment;               // increment to move the servo for each interval
int updateInterval;          // interval between servo position updates
unsigned long lastUpdate;    // last update of servo position

void setup() {
pinMode(PIEZO, OUTPUT);      // set pins to either input or output
pinMode(TURRET, OUTPUT);
pinMode(LEDW, OUTPUT);
pinMode(LEDR, OUTPUT);
pinMode(LEDG, OUTPUT);
pinMode(LASREC, INPUT);
pinMode(LASEROUT, OUTPUT);
pinMode(ULTRAT, OUTPUT);
pinMode(ULTRAE, INPUT);
pinMode(MOTONEA, OUTPUT);
pinMode(MOTONEB, OUTPUT);
pinMode(MOTTWOA, OUTPUT);
pinMode(MOTTWOB, OUTPUT);

updateInterval = 25;         // servo sweep update interval
increment = 1;               // amount to move servo angle per interval
myservo.attach(TURRET);      // attach the servo to the TURRET pin

delay(5000);                 // five second delay after powering on to place tank in starting position
Serial.begin(9600);          // initialize serial connection so that we can print values
randomSeed(analogRead(0));   // seed to randomize first number generated for turning
}

void loop() {
  
tankSeek();
turretSweep();
fire();
//thebeep();
echo();

}

void echo(){                                        // This function polls the ultrasonic sensor
  if(millis() > time_echo + interval_echo){         // and stores the value in the 'range' variable. 
    time_echo = millis();
 //   Serial.println("");
    range = distanceSensor.measureDistanceCm();
    echocheck();                                    // filter out values of -1.00
//    Serial.print(range);
  }

}

void tankSeek(){
 if(range >= 20 && rotate == 0){
  forward();                                            // if distance from sensor to object is greater than 20cm, move forward
  turn_direction = random(0, 2);                        // randomly choose 0 or 1 to turn left or right
  interval_rotate = random(500, 1000);                  // set turn duration to between 1.0 to 2.0 seconds
 }
 if(range < 20){
  rotate = 1;                                           // begin turning
  time_rotate = millis();
 }
 if(rotate == 1){                                       // if distance from sensor to object is less than 20cm, turn either left or right

  if(millis() < time_rotate + interval_rotate){         // Rotate left or right until interval_rotate has elapsed
   if(turn_direction == 0){
    turnleft();
   }
   if(turn_direction == 1){
    turnright();
   }
  }
  if(millis() > time_rotate + interval_rotate){         // stop rotating when interval_rotate has elapsed
    rotate = 0;                                         // stop turning
  }
 }
}

void echocheck(){                       // ultrasonic sensor sometimes returns value of -1
   if(range <= 0)                       // this filter converts any value under 0 to 21 to fix this
    {
      range = 21;
    }
}

void fire(){
  if(millis() > time_fire + interval_laser){
  time_fire = millis();
  digitalWrite(LASEROUT, laser);
  laser = !laser;
  }
}

void thebeep(){  
  if(millis() > time_beeps + interval_beep){
  time_beeps = millis();
  tone(PIEZO, 1000, 5);
  }
}


void turretSweep()
  {
    if((millis() - lastUpdate) > updateInterval)  // time to update
    {
      lastUpdate = millis();
      pos += increment;
      myservo.write(pos);
      if ((pos >= 135) || (pos <= 25))            // end of sweep
      {
        increment = -increment;                   // reverse direction
      }
    }
  }

void forward(){
  analogWrite(MOTONEA, MOTONESPD);     //set the pins on the motor controller to move forward
  analogWrite(MOTONEB, 0);
  analogWrite(MOTTWOA, MOTTWOSPD);
  analogWrite(MOTTWOB, 0);
  }

void reverse(){
  analogWrite(MOTONEA, 0);             //set the pins on the motor controller to move in reverse
  analogWrite(MOTONEB, MOTONESPD);
  analogWrite(MOTTWOA, 0);
  analogWrite(MOTTWOB, MOTTWOSPD);
  }

void turnright(){
  analogWrite(MOTONEA, 0);             //set the pins on the motor controller to turn right
  analogWrite(MOTONEB, MOTONESPD);
  analogWrite(MOTTWOA, MOTTWOSPD);
  analogWrite(MOTTWOB, 0);
  }

void turnleft(){
  analogWrite(MOTONEA, MOTONESPD);     //set the pins on the motor controller to turn left
  analogWrite(MOTONEB, 0);
  analogWrite(MOTTWOA, 0);
  analogWrite(MOTTWOB, MOTTWOSPD);
  }
