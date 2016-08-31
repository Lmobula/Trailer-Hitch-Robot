#include <XBOXRECV.h>

const int actrCtrlPin1 = 2;             //Pin to control actuator movement
const int actrCtrlPin2 = 3;             //Pin to control actuator movement
const int hallSensorPin = A0;           //Pin to read Hall Effect Sensor
const PIN_BUTTON_A = 20;
const PIN_BUTTON_B = 21;
const int limitTop = 100;               //Value from Hall Effect Sensor for max extension
const int limitBot = 0;                 //Value from Hall Effect Sensor for max retraction

int motorDir = 8; //Dir 1
int motorSpeed = 9; //PWM 1
int motorDir2 = 10; //Dir 2
int motorSpeed2 = 11; //PWM2
int forward_movement;
int backward_movement;

USB Usb;
XBOXRECV Xbox(&Usb);

void setup() {
  Serial.begin(115200);
  Usb.Init(); 
  pinMode(actrCtrlPin1, OUTPUT);
  pinMode(actrCtrlPin2, OUTPUT);
  pinMode(motorDir, OUTPUT); //Movement Part
  pinMode(motorDir2, OUTPUT); //Movement Part
  pinMode(motorSpeed, OUTPUT); //Movement Part
  pinMode(motorSpeed2, OUTPUT); //Movement Part
   pinMode(PIN_BUTTON_A, INPUT);
digitalWrite(PIN_BUTTON_A, LOW);
 pinMode(PIN_BUTTON_B, INPUT);
digitalWrite(PIN_BUTTON_B, LOW);
}

void loop() {
  Usb.Task();
  if (Xbox.XboxReceiverConnected) {
    int pos = analogRead(hallSensorPin);                  //Get actuator vertical position
    if (Xbox.getAnalogHat(RightHatY , 0) > 1000) {        //Check if Right Stick is in up direction
      if (pos < limitTop) {                               //Check if actuator can extend
        actuatorUp();
      } else {
        actuatorHold();
      }
    } 
    else if(Xbox.getAnalogHat(RightHatY, 0) < 1000) {   //Check if Right Stick is in down direction
      if (pos > limitBot) {                               //Check if actuator can retract
        actuatorDown();
      } 
      else {
        actuatorHold();
      }
    } 
    else if(Xbox.getAnalogHat(LeftHatY, 0) > 1000) {
      //going forward
      
    } 
    else if(Xbox.getAnalogHat(LeftHatY, 0) < 1000) {   //Check if Right Stick is in down direction
      //going backwards
      //buzzard
    }
    else if(Xbox.getAnalogHat(LeftHatX, 0) > 1000) {
      //going right???
    } 
    else if(Xbox.getAnalogHat(LeftHatX, 0) < 1000) {   //Check if Right Stick is in down direction
      //going left???
    }
    else if (digitalRead(PIN_BUTTON_A) == LOW) {
    // Button is pressed
    ButtonA_pressed();
    }
    else if (digitalRead(PIN_BUTTON_B) == LOW) {
    // Button is pressed
    ButtonB_pressed();
    }
    else {                                              //If Right Stick is not moved
      actuatorHold();                                
      // Motor is at 0 for driving
    }
    delay(1);
  }
delay(1);
}

void actuatorUp() {
  digitalWrite(actrCtrlPin1, HIGH);
  digitalWrite(actrCtrlPin2, LOW);
}

void actuatorDown() {
  digitalWrite(actrCtrlPin1, LOW);
  digitalWrite(actrCtrlPin2, HIGH);
}

void actuatorHold() {
  digitalWrite(actrCtrlPin1, LOW);
  digitalWrite(actrCtrlPin2, LOW);
}



//Stephanie Stuff for movement

//Laura

void ButtonA_pressed(){
if (PIN_BUTTON_A) == LOW) {                        // Button A is pressed
  both motors move forward at same speed at certain time();
}
  else {
    both motors move backward at same speed at certain time();
  }
}

void ButtonB_pressed(){
if (PIN_BUTTON_B) == LOW) {                     // Buttom B is pressed
  all motors stop ();
}
  else {
    press BUTTON_B to start the system ();
  }
}






