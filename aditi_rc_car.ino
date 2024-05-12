#include<AFMotor.h>
#define trig1 A0
#define echo1 A1
#define trig2 A2
#define echo2 A3
#define trig3 A4
#define echo3 A5
/*#define redled 7
#define blueled 8
#define buzzer 4*/
char value;
long duration, d1=0,d2=0,d3=0;
float distance, distance2, distance3, u1=0,u2=0,u3=0;
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);
void setup()
{
 Serial.begin(9600);
 pinMode(trig1, OUTPUT);
 pinMode(trig2, OUTPUT);
 pinMode(trig3, OUTPUT);
 pinMode(echo1, INPUT);
 pinMode(echo2, INPUT);
 pinMode(echo3, INPUT);
}
void loop()
{
 Bluetooth();
}
void Bluetooth()
{
 if (Serial.available()>0)
 {
 value=Serial.read();
 Serial.println(value);
 }
 if(value == 'F')
 {
 forward();
 U1();
 }
 else if(value == 'B')
 {
 backward();
 }
 else if(value == 'L')
 {
 left();
 }
 else if(value == 'R')
 {
 right();
 }
 /* else if (value == 'G') {
 forwardLeft();
 } 
 else if (value == 'I') {
 forwardRight();
 } */
 else
 {
 Stop();
 }
}
void U1()
{
 digitalWrite(trig1,LOW);
 delayMicroseconds(2);
 digitalWrite(trig1,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig1,LOW);
 duration = pulseIn(echo1,HIGH);
 d1 = (duration*0.034)/2;
 if(d1 < 35)
 {
 reverse();
 }
}
void U2()
{
 digitalWrite(trig2,LOW);
 delayMicroseconds(2);
 digitalWrite(trig2,HIGH);
 delayMicroseconds(15);
 digitalWrite(trig2,LOW);
 duration = pulseIn(echo2,HIGH);
 d2 = (duration*29)/2;
 Serial.println(d2);
 if(d2<35)
 {
 reverse();
}
}
void U3()
{
 digitalWrite(trig3,LOW);
 delayMicroseconds(2);
 digitalWrite(trig3,HIGH);
 delayMicroseconds(15);
 digitalWrite(trig3,LOW);
 duration = pulseIn(echo3,HIGH);
 d3 = (duration*29)/2;
 Serial.println(d3);
 if(d3<35)
 {
 reverse();
 }
}
void forward() {
 M1.setSpeed(180);
 M2.setSpeed(180);
 M3.setSpeed(180);
 M4.setSpeed(180);
 M1.run(FORWARD);
 M2.run(FORWARD);
 M3.run(FORWARD);
 M4.run(FORWARD);
}
void backward() {
 M1.setSpeed(150);
 M2.setSpeed(150);
 M3.setSpeed(150);
 M4.setSpeed(150);
 M1.run(BACKWARD);
 M2.run(BACKWARD);
 M3.run(BACKWARD);
 M4.run(BACKWARD);
}
void left() {
 M1.run(BACKWARD);
 M2.run(BACKWARD);
 M3.run(FORWARD);
 M4.run(FORWARD);
}
void right () {
 M1.setSpeed(150);
 M2.setSpeed(150);
 M3.setSpeed(150);
 M4.setSpeed(150);
 M1.run(FORWARD);
 M2.run(FORWARD);
 M3.run(BACKWARD);
 M4.run(BACKWARD);
}
void forwardLeft()
{ 
 u1=U1();
 u2=U2(); 
 if(u2>40 && u1>50)
{
 M1.setSpeed(140);
 M2.setSpeed(140);
 M3.setSpeed(180);
 M4.setSpeed(180);
 M1.run(FORWARD);
 M2.run(FORWARD);
 M3.run(FORWARD);
 M4.run(FORWARD);
 digitalWrite(blueled,HIGH);
 Bluetoothcontrol();
}
if(u2>30 && u1>40)
{
 M1.setSpeed(120);
 M2.setSpeed(120);
 M3.setSpeed(160);
 M4.setSpeed(160);
 M1.run(FORWARD);
 M2.run(FORWARD);
 M3.run(FORWARD);
 M4.run(FORWARD);
 digitalWrite(blueled,LOW);
 digitalWrite(redled,HIGH);
 Bluetoothcontrol();
}
if(u2>15 && u1>20)
{
 M1.setSpeed(100);
 M2.setSpeed(100);
 M3.setSpeed(140);
 M4.setSpeed(140);
 M1.run(FORWARD);
 M2.run(FORWARD);
 M3.run(FORWARD);
 M4.run(FORWARD);
 digitalWrite(redled,HIGH);
 digitalWrite(buzzer,HIGH);
 Bluetoothcontrol();
}
}
void forwardRight()
{
u1=U1();
u3=U2(); 
if(u3>40 && u1>50)
{
 M1.setSpeed(180);
 M2.setSpeed(180);
 M3.setSpeed(140);
 M4.setSpeed(140);
 M1.run(FORWARD);
 M2.run(FORWARD);
 M3.run(FORWARD);
 M4.run(FORWARD);
 digitalWrite(blueled,HIGH);
 Bluetoothcontrol();
}
if(u3>30 && u1>40)
{
 M1.setSpeed(160);
 M2.setSpeed(160);
 M3.setSpeed(120);
 M4.setSpeed(120);
 M1.run(FORWARD);
 M2.run(FORWARD);
 M3.run(FORWARD);
 M4.run(FORWARD);
 digitalWrite(blueled,LOW);
 digitalWrite(redled,HIGH);
 Bluetoothcontrol();
}
if(u3>15 && u1>20)
{
 M1.setSpeed(140);
 M2.setSpeed(140);
 M3.setSpeed(100);
 M4.setSpeed(100);
 M1.run(FORWARD);
 M2.run(FORWARD);
 M3.run(FORWARD);
 M4.run(FORWARD);
 digitalWrite(redled,HIGH);
 digitalWrite(buzzer,HIGH);
 Bluetoothcontrol();
}
}
}
void Stop() {
 M1.run(RELEASE);
 M2.run(RELEASE);
 M3.run(RELEASE);
 M4.run(RELEASE);
}
void reverse() {
 M1.setSpeed(250);
 M2.setSpeed(250);
 M3.setSpeed(250);
 M4.setSpeed(250);
 M1.run(BACKWARD);
 M2.run(BACKWARD);
 M3.run(BACKWARD);
 M4.run(BACKWARD);
 
}
 
