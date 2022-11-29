/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button
 */

// constants won't change. They're used here to set pin numbers:

#include <Joystick.h>

Joystick_ Joystick;



const int BUTTON_PIN = 4;       // the number of the pushbutton pin
const int BUTTON_PIN2 = 5;
const int BUTTON_PIN3 = 6;
const int BUTTON_PIN4 = 9;
const int BUTTON_PIN5 = 14;
const int BUTTON_PIN6 = 3;
const int BUTTON_PIN7 = 19;


#define CLK 10
#define DT 16

#define CLK2 7
#define DT2 8

#define CLK3 15
#define DT3 18


int currentStateCLK;
int lastStateCLK;
String currentDir ="";

int currentStateCLK2;
int lastStateCLK2;

int currentStateCLK3;
int lastStateCLK3;

// Variables will change:
int lastState = LOW;  // the previous state from the input pin
int currentState;                // the current reading from the input pin

int lastState2 = LOW;
int currentState2;

int lastState3 = LOW;
int currentState3;

int lastState4 = LOW;
int currentState4;

int lastState5 = LOW;
int currentState5;

int lastState6 = LOW;
int currentState6;

int lastState7 = LOW;
int currentState7;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the pushbutton pin as an pull-up input
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
  pinMode(BUTTON_PIN5, INPUT_PULLUP);
  pinMode(BUTTON_PIN6, INPUT_PULLUP);
  pinMode(BUTTON_PIN7, INPUT_PULLUP);



  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(CLK2,INPUT);
  pinMode(DT2,INPUT);
  pinMode(CLK3,INPUT);
  pinMode(DT3,INPUT);

  lastStateCLK = digitalRead(CLK);
  lastStateCLK2 = digitalRead(CLK2);
  lastStateCLK3 = digitalRead(CLK3);


  Joystick.begin();

}

void loop() {
  delay(1);
  // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);
  currentState2 = digitalRead(BUTTON_PIN2);
  currentState3 = digitalRead(BUTTON_PIN3);
  currentState4 = digitalRead(BUTTON_PIN4);
  currentState5 = digitalRead(BUTTON_PIN5);
  currentState6 = digitalRead(BUTTON_PIN6);
  currentState7 = digitalRead(BUTTON_PIN7);


  if(lastState == HIGH && currentState == LOW){
    Serial.println("The button is pressed");
    Joystick.setButton(0, 1);
  }
    
  else if(lastState == LOW && currentState == HIGH){
    Serial.println("The button is released");
    Joystick.setButton(0, 0);
  }

    

  if(lastState2 == HIGH && currentState2 == LOW){
    Serial.println("The button2 is pressed");
    Joystick.setButton(1, 1);
  }
    
  else if(lastState2 == LOW && currentState2 == HIGH){
    Serial.println("The button2 is released");
    Joystick.setButton(1, 0);
  }

  if(lastState3 == HIGH && currentState3 == LOW){
    Serial.println("The button2 is pressed");
    Joystick.setButton(2, 1);
  }
    
  else if(lastState3 == LOW && currentState3 == HIGH){
    Serial.println("The button2 is released");
    Joystick.setButton(2, 0);
  }

  if(lastState4 == HIGH && currentState4 == LOW){
    Serial.println("The button2 is pressed");
    Joystick.setButton(3, 1);
  }
    
  else if(lastState4 == LOW && currentState4 == HIGH){
    Serial.println("The button2 is released");
    Joystick.setButton(3, 0);
  }

  if(lastState5 == HIGH && currentState5 == LOW){
    Serial.println("The button2 is pressed");
    Joystick.setButton(6, 1);
  }
    
  else if(lastState5 == LOW && currentState5 == HIGH){
    Serial.println("The button2 is released");
    Joystick.setButton(6, 0);
  }

  if(lastState6 == HIGH && currentState6 == LOW){
    Serial.println("The button6 is pressed");
    Joystick.setButton(7, 1);
  }
    
  else if(lastState6 == LOW && currentState6 == HIGH){
    Serial.println("The button6 is released");
    Joystick.setButton(7, 0);
  }

  if(lastState7 == HIGH && currentState7 == LOW){
    Serial.println("The button6 is pressed");
    Joystick.setButton(10, 1);
  }
    
  else if(lastState7 == LOW && currentState7 == HIGH){
    Serial.println("The button6 is released");
    Joystick.setButton(10, 0);
  }



  // save the the last state
  lastState = currentState;
  lastState2 = currentState2;
  lastState3 = currentState3;
  lastState4 = currentState4;
  lastState5 = currentState5;
  lastState6 = currentState6;
  lastState7 = currentState7;



  currentStateCLK = digitalRead(CLK);
  currentStateCLK2 = digitalRead(CLK2);
  currentStateCLK3 = digitalRead(CLK3);

  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {
      currentDir ="CCW";
      Joystick.pressButton(4);
      delay(50);
      Joystick.releaseButton(4);
    } else {
      // Encoder is rotating CW so increment
      currentDir ="CW";
      Joystick.pressButton(5);
      delay(50);
      Joystick.releaseButton(5);
    }

    Serial.print("Direction: ");
    Serial.println(currentDir);
  }

  if (currentStateCLK2 != lastStateCLK2  && currentStateCLK2 == 1){

    // If the DT2 state is different than the CLK2 state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT2) != currentStateCLK2) {
      currentDir ="CCW";
      Joystick.pressButton(8);
      delay(50);
      Joystick.releaseButton(8);
    } else {
      // Encoder is rotating CW so increment
      currentDir ="CW";
      Joystick.pressButton(9);
      delay(50);
      Joystick.releaseButton(9);
    }

    Serial.print("Direction: ");
    Serial.println(currentDir);
  }

  if (currentStateCLK3 != lastStateCLK3  && currentStateCLK3 == 1){

    // If the DT2 state is different than the CLK2 state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT3) != currentStateCLK3) {
      currentDir ="CCW";
      Joystick.pressButton(11);
      delay(50);
      Joystick.releaseButton(11);
    } else {
      // Encoder is rotating CW so increment
      currentDir ="CW";
      Joystick.pressButton(12);
      delay(50);
      Joystick.releaseButton(12);
    }

    Serial.print("Direction: ");
    Serial.println(currentDir);
  }

  // Remember last CLK state
  lastStateCLK = currentStateCLK;
  lastStateCLK2 = currentStateCLK2;
  lastStateCLK3 = currentStateCLK3;


}
