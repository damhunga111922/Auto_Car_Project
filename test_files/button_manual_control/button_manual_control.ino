#include <Stepper.h>

const int closeButton = 2; 
const int openButton = 3;
const int closeSw = 4;
const int openSw = 5;
 
int closeButtonState = 0;  
int openButtonState = 0;  
int closeSwState = 0;
int openSwState = 0;

const int stepsPerRevolution = 128;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  pinMode(closeButton, INPUT);
  pinMode(openButton, INPUT);
  myStepper.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  closeButtonState = digitalRead(closeButton);
  openButtonState = digitalRead(openButton);
  closeSwState = digitalRead(closeSw);
  openSwState = digitalRead(openSw);

  Serial.print("nut dong:");
  Serial.println(closeButtonState);
  Serial.print("nut mo:");
  Serial.println(openButtonState);
  Serial.print("sw dong:");
  Serial.println(closeSwState);
  Serial.print("sw mo:");
  Serial.println(openSwState);
//1
  if(closeButtonState == 0 && openButtonState == 0 && closeSwState == 0 && openSwState == 0 ){
    stop();
  }
//2
  if(closeButtonState == 0 && openButtonState == 0 && closeSwState == 0 && openSwState == 1 ){
    stop();
  }
//3
  if(closeButtonState == 0 && openButtonState == 0 && closeSwState == 1 && openSwState == 0 ){
    stop();
  }
//4
  if(closeButtonState == 0 && openButtonState == 0 && closeSwState == 1 && openSwState == 1 ){
    stop();
  }
//5
  if(closeButtonState == 0 && openButtonState == 1 && closeSwState == 0 && openSwState == 0 ){
    open();
  }
//6
  if(closeButtonState == 0 && openButtonState == 1 && closeSwState == 0 && openSwState == 1 ){
    stop();
  }
//7
  if(closeButtonState == 0 && openButtonState == 1 && closeSwState == 1 && openSwState == 0 ){
    open();
  }
//8
  if(closeButtonState == 0 && openButtonState == 1 && closeSwState == 1 && openSwState == 1 ){
    stop();
  }
//9
  if(closeButtonState == 1 && openButtonState == 0 && closeSwState == 0 && openSwState == 0 ){
    close();
  }
//10
  if(closeButtonState == 1 && openButtonState == 0 && closeSwState == 0 && openSwState == 1 ){
    close();
  }
//11
  if(closeButtonState == 1 && openButtonState == 0 && closeSwState == 1 && openSwState == 0 ){
    stop();
  }
//12
  if(closeButtonState == 1 && openButtonState == 0 && closeSwState == 1 && openSwState == 1 ){
    stop();
  }
//13
  if(closeButtonState == 1 && openButtonState == 1 && closeSwState == 0 && openSwState == 0 ){
    stop();
  }
//14
  if(closeButtonState == 1 && openButtonState == 1 && closeSwState == 0 && openSwState == 1 ){
    stop();
  }
//15
  if(closeButtonState == 1 && openButtonState == 1 && closeSwState == 1 && openSwState == 0 ){
    stop();
  }
//16
  if(closeButtonState == 1 && openButtonState == 1 && closeSwState == 1 && openSwState == 1 ){
    stop();
  }  
//delay(1000);
}


void open(){
    myStepper.step(-stepsPerRevolution);
    Serial.println("Cua dang mo");
}
void close(){
    myStepper.step(stepsPerRevolution);
    Serial.println("Cua dang dong");
}
void stop(){
    myStepper.step(0);
    Serial.println("Cua dung");
}

