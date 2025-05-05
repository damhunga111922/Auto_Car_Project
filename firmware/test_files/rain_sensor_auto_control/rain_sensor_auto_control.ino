#include <Stepper.h>

const int closeSw = 4;
const int openSw = 5;
const int rainSensorPin = 6; 

int closeSwState = 0;
int openSwState = 0;
int rainState = 0;

const int stepsPerRevolution = 128;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  pinMode (closeSw, INPUT);
  pinMode (openSw, INPUT);
  pinMode(rainSensorPin, INPUT);
  myStepper.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  closeSwState = digitalRead(closeSw);
  openSwState = digitalRead(openSw);
  rainState = digitalRead(rainSensorPin);

  Serial.print("sw dong:");
  Serial.println(closeSwState);
  Serial.print("sw mo:");
  Serial.println(openSwState);
  Serial.print("trang thai mua:");
  Serial.println(rainState);

//1
  if(rainState == 0 && closeSwState == 0 && openSwState == 0 ){
    close();
  }
//2
  if(rainState == 0 && closeSwState == 0 && openSwState == 1 ){
    close();
  }
//3
  if(rainState == 0 && closeSwState == 1 && openSwState == 0 ){
    stop();
  }
//4
  if(rainState == 0 && closeSwState == 1 && openSwState == 1 ){
    stop();
  }  
//5
  if(rainState == 1 && closeSwState == 0 && openSwState == 0 ){
    open();
  }
//6
  if(rainState == 1 && closeSwState == 0 && openSwState == 1 ){
    stop();
  }
//7
  if(rainState == 1 && closeSwState == 1 && openSwState == 0 ){
    open();
  }
//8
  if(rainState == 1 && closeSwState == 1 && openSwState == 1 ){
    stop();
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
void stop(){
    myStepper.step(0);
    Serial.println("Cua dung");
}

