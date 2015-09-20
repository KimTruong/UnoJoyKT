
#include "UnoJoy.h"

void setup(){
  setupPins();
  setupUnoJoy();
}

void loop(){
  // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
  // Set all the digital pins as inputs
  // with the pull-up enabled, except for the 
  // two serial line pins
  for (int i = 2; i <= 12; i++){
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }
  /*pinMode(A4, INPUT);
  digitalWrite(A4, HIGH);
  pinMode(A5, INPUT);
  digitalWrite(A5, HIGH);*/
}

dataForController_t getControllerData(void){
  
  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins
  controllerData.triangleOn = 0; //!digitalRead(2);
  controllerData.circleOn = 0; //!digitalRead(3);
  controllerData.squareOn = 0; //!digitalRead(4);
  controllerData.crossOn = 0; //!digitalRead(5);
  controllerData.dpadUpOn = !digitalRead(6);
  controllerData.dpadDownOn = !digitalRead(7);
  controllerData.dpadLeftOn = !digitalRead(8);
  controllerData.dpadRightOn = !digitalRead(9);
  controllerData.l1On = !digitalRead(10);
  controllerData.r1On = !digitalRead(11);
  controllerData.selectOn = !digitalRead(12);
  controllerData.startOn = 0; //!digitalRead(A4);
  controllerData.homeOn = 0; //!digitalRead(A5);
  
  // Set the analog sticks
  //  Since analogRead(pin) returns a 10 bit value,
  //  we need to perform a bit shift operation to
  //  lose the 2 least significant bits and get an
  //  8 bit number that we can use  
  controllerData.leftStickX = analogRead(A0) >> 2;
  controllerData.leftStickY = ((analogRead(A3) / 2) >> 2) + 128 - ((analogRead(A1) / 2) >> 2);
  
  //controllerData.leftStickY = analogRead(A1) >> 2;
  
  controllerData.rightStickX = analogRead(A2) >> 2;
  //controllerData.rightStickY = analogRead(A3) >> 2;
  controllerData.centerStickX = analogRead(A4) >> 2;
  controllerData.centerStickY = analogRead(A5) >> 2;
  
  if ((controllerData.centerStickX <= 64) and (controllerData.centerStickY >=192)) {controllerData.triangleOn=1;} else {controllerData.triangleOn=0;}
  if ((controllerData.centerStickX <= 64) and (controllerData.centerStickY <=64)) {controllerData.circleOn=1;} else {controllerData.circleOn=0;}
  if ((controllerData.centerStickX >= 192) and (controllerData.centerStickY >=192)) {controllerData.squareOn=1;} else {controllerData.squareOn=0;}
  if ((controllerData.centerStickX >= 192) and (controllerData.centerStickY <=64)) {controllerData.crossOn=1;} else {controllerData.crossOn=0;}
  if ((controllerData.centerStickX >= 96) and (controllerData.centerStickX <=160) and (controllerData.centerStickY >=192)) {controllerData.startOn=1;} else {controllerData.startOn=0;}
  if ((controllerData.centerStickX >= 96) and (controllerData.centerStickX <=160) and (controllerData.centerStickY <=64)) {controllerData.homeOn=1;} else {controllerData.homeOn=0;}
  // And return the data!
  return controllerData;
}
