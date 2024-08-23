#ifndef MakistCar_h
#define MakistCar_h

#ifdef NOT_MAKIST_CAR_KIT
#else
#define SERVO_PIN 16
#define L_MOTOR_A_PIN 2
#define L_MOTOR_B_PIN 4
#define R_MOTOR_A_PIN 13
#define R_MOTOR_B_PIN 27

#define TRIG_PIN 32
#define ECHO_PIN 23

#define RIGHT_LED_PIN 33
#define LEFT_LED_PIN 17
#define IR1_PIN 35
#define IR2_PIN 34
#define IR3_PIN 39
#define IR4_PIN 36
#endif

#define NO_ECHO 0
#define MAX_DISTANCE 200
#define MAX_SENSOR_DELAY 5800
#define MAX_SENSOR_DISTANCE 500
#define US_ROUNDTRIP_CM 57
#define PING_OVERHEAD 1

#include "Arduino.h"
#include <NewPing.h>
#include <ESP32Servo.h>

class MakistCar
{
private:
   int centerAngle = 90;
   int maxAngle = 35;
   Servo servo;
   unsigned int maxEchoTime;
   unsigned long maxTime;
   int minSpeed = 70;
   int maxSpeed = 255;
   int motorDir = 1;

public:
   void pinInit(int pwmFreq = 5000, int pwmResolution = 8);
   void ledOn();
   void ledOff();
   void direction(); // Motor direction control
   void speed(int speed);
   void leftSpeed(int speed);
   void rightSpeed(int speed);
   void servoWrite(int value);
   void servoAngle(int value);
   void handleOffset(int _centerAngle, int _maxAngle);
   void handle(char value);
   unsigned int getMM(); // Return distance value in 'mm'
   void setMaxDistance(unsigned int max_cm_distance);
   boolean pingTrigger();
   int irCheck(int reference = 500); // Return IR State
   int irSideCheck(int reference = 500);
   int irMidCheck(int reference = 500);
};
#endif