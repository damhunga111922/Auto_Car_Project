#include <Stepper.h>

const int closeButton = 2; 
const int openButton = 3;
const int closeSw = 4;
const int openSw = 5;
const int rainSensorPin = 6;
const int modePin = 7;
const int infraredSensor = 12; 
 
int closeButtonState = 0;  
int openButtonState = 0;  
int closeSwState = 0;
int openSwState = 0;
int rainState = 0;
int mode = 0;
int infraredSensorState = 0;

const int stepsPerRevolution = 32;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  pinMode(closeButton, INPUT);
  pinMode(openButton, INPUT);
  pinMode (closeSw, INPUT);
  pinMode (openSw, INPUT);
  pinMode(rainSensorPin, INPUT);
  pinMode (infraredSensor, INPUT);
  myStepper.setSpeed(60);
  Serial.begin(9600);
}

void loop(){
  infraredSensorState = digitalRead(infraredSensor);
  if(infraredSensorState == 0){
    Serial.println("Co vat can");
    stop();
  }
  if(infraredSensorState == 1){
    mode = digitalRead(modePin);
  if(mode == 0){
    Serial.println("Che do thu cong");
    manual_control();
  }
  if(mode == 1){
    Serial.println("Che do tu dong");
    auto_control();
  }
}

}


void manual_control() {
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

void auto_control() {
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
    myStepper.step(stepsPerRevolution);
    Serial.println("Cua dang mo");
}
void close(){
    myStepper.step(-stepsPerRevolution);
    Serial.println("Cua dang dong");
}
void stop(){
    myStepper.step(0);
    Serial.println("Cua dung");
}

