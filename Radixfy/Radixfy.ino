#include <Servo.h>
//#include <NewPing.h>
#define rad 360
#define MAX_DISTANCE 400
#define TRIG_PIN 7
int x=0;
#define ECHO_PIN 8
long duration;
int distance;
Servo rad_ser;
//NewPing sonar(trigger_pin,echo_pin,MAX_DISTANCE);
void setup() {
  // put your setup code here, to run once:
    rad_ser.attach(3);
    pinMode(ECHO_PIN,INPUT);
    pinMode(TRIG_PIN,OUTPUT);
    Serial.begin(9600);
}
int serv_run(){
  if(x<180){
    rad_ser.write(x);
  }
  else{
    rad_ser.write(rad-x);
  }
  x++;
  if(x==360)
    x=0;
}
int getdistandsend() {
  int sumv=0;
  for(int i =0;i<10;i++){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance= duration*0.034/2;
  if(distance<150)
  sumv+=distance;
  }
  sumv/=10;
  
    Serial.println(sumv);
}
void loop() {
  // put your main code here, to run repeatedly:
  delay(50);
  serv_run();
  getdistandsend(); 
}
