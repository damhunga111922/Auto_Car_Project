#include <Servo.h>

Servo myservo;

const int modeButton = 8; 
const int manualcontrolButton = 7;
const int sweepSpeedLevel1 = 2;
const int sweepSpeedLevel3 = 3;

const int rainSensorDigitalPin = 6;
const int rainSensorAnalogPin = A1;

 
int modeState = 0;  
int manualcontrolState = 0;  
int sweepSpeedLevel1State = 0;
int sweepSpeedLevel3State = 0;

int rainStateDigital = 0;
int rainStateAnalog = 0;
int pos = 0;


void setup() {
  pinMode(modeButton, INPUT);
  pinMode(manualcontrolButton, INPUT);
  pinMode(sweepSpeedLevel1, INPUT);
  pinMode(sweepSpeedLevel3, INPUT);
  pinMode(rainSensorDigitalPin, INPUT);
  pinMode(rainSensorAnalogPin, INPUT);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop(){
  modeState = digitalRead(modeButton);
  Serial.println(modeState);
// Serial.println(manualcontrolState);
  if(modeState == 0){
    Serial.println("Che do thu cong");
    manualcontrol();
  }
  if(modeState == 1){
    Serial.println("Che do tu dong");
    autocontrol();
  }
}

void autocontrol(){
  rainStateAnalog = analogRead(rainSensorAnalogPin);
  Serial.println(rainStateAnalog);
//0
  if (rainStateAnalog >= 900){
  myservo.write(30);
  }
//1
  if (rainStateAnalog < 900 & rainStateAnalog >= 450){
  myservo.write(30);
  delay(1500);
  myservo.write(120);
  delay(1500);
  }
//2
  if (rainStateAnalog < 450 & rainStateAnalog >=380){
  myservo.write(30);
  delay(1000);
  myservo.write(120);
  delay(1000);
  }
//3
  if (rainStateAnalog < 380){
  myservo.write(30);
  delay(500);
  myservo.write(120);
  delay(500);
  }
}

void manualcontrol(){
  manualcontrolState = digitalRead(manualcontrolButton);
  sweepSpeedLevel1State = digitalRead(sweepSpeedLevel1);
  sweepSpeedLevel3State = digitalRead(sweepSpeedLevel3);
//Serial.println(sweepSpeedLevel1State);
//Serial.println(sweepSpeedLevel3State);
  if(manualcontrolState == 0){
    myservo.write(30);
  }
  if(manualcontrolState == 1){
//1
  if (sweepSpeedLevel1State == 1 & sweepSpeedLevel3State == 0){
    myservo.write(30);
    delay(1500);
    myservo.write(120);
    delay(1500);
  }
//2
  if (sweepSpeedLevel1State == 0 & sweepSpeedLevel3State == 0){
  myservo.write(30);
  delay(1000);
  myservo.write(120);
  delay(1000);
  }
//3
  if (sweepSpeedLevel1State == 0 & sweepSpeedLevel3State == 1){
  myservo.write(30);
  delay(500);
  myservo.write(120);
  delay(500);
  }
}

}
