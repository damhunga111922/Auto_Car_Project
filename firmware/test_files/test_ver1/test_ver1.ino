#include <Stepper.h>

const int closeButton = 2; 
const int openButton = 3;

int closeButtonState = 0;  
int openButtonState = 0;  
const int stepsPerRevolution = 1024;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  pinMode(closeButton, INPUT);
  pinMode(openButton, INPUT);
  myStepper.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  closeState = digitalRead(closeButton);
  openState = digitalRead(openButton);
  Serial.print("tin hieu dong:");
  Serial.println(closeState);
  Serial.print("tin hieu mo:");
  Serial.println(openState);
  delay(200);
    if(closeState == 0 && openState == 1){
    open();
  }
  if(closeState == 1 && openState == 0){
    close();
  }
}
void open(){
    myStepper.step(-stepsPerRevolution);
    Serial.println("Cua dang mo");
}
void close(){
    myStepper.step(stepsPerRevolution);
    Serial.println("Cua dang dong");
}


