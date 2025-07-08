#include "Squeeze.h" // Squeeze_length and Squeeze_data give audio array length and audio array
#include "Open.h"
#include "Close.h"
int buttonPressed = 0;
int buttonPin = 27;
int buttonCnt = 0;
int lastButtonState = 0;
int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(921600);
pinMode(buttonPin,INPUT);

}

void loop() {

  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  
  if (lastButtonState == 0 && buttonState == 1){
    buttonCnt++;
    delay(500);
    switch (buttonCnt){
  
  case 0:
      Serial.println(buttonCnt);
    break;

  case 1: 
      playAudio(Open_length, Open_data); 
    break;
        
  case 2:
      playAudio(Close_length, Close_data); 
    break;

  case 3:
      Serial.println("Playing audio #3");
      playAudio(Squeeze_length, Squeeze_data); 
      buttonCnt = 0;
    break;

  default:
      Serial.println("press button to activate");
    break;

  }
 
  }

  lastButtonState = buttonState;

  // put a switch on buttonCnt to play each audio per press of button

}

