#ifndef MakistCar_h
#define MakistCar_h

#include "Arduino.h"
#include <ESP32Servo.h>
#include <NewPing.h>

#ifdef NOT_MAKIST_CAR_KIT
#else
#define SERVO_PIN 16
#define L_MOTOR_FORWARD_PIN 2
#define L_MOTOR_REVERSE_PIN 4
#define R_MOTOR_FORWARD_PIN 13
#define R_MOTOR_REVERSE_PIN 27

#define TRIG_PIN 32
#define ECHO_PIN 23
#define RIGHT_LED_PIN 33
#define LEFT_LED_PIN 17
#define IR1_PIN 35
#define IR2_PIN 34
#define IR3_PIN 39
#define IR4_PIN 36
#endif
class DC_Motor_Control
{
private:
   const int _Forward_Pin;
   const int _Reverse_Pin;

public:
   DC_Motor_Control(int Forward_Pin, int Reverse_Pin, int pwmFreq = 5000, int pwmResolution = 8);

   void Speed(int Forward, int Reverse);
   void Stop_N(); // Neutral
   void Stop_B(); // Break
};

class SERVO_MOTOR_CONTROL
{
private:
   const int _Center_Angle;
   const int _Max_Angle;
   Servo _servo;

public:
   SERVO_MOTOR_CONTROL(int Center_Angle = 90, int Max_Angle = 35);

   void write(int value);
   void Angle(int value);
   void Handle(char value);
};

class ULTRASONIC_CONTROL
{
private:
   NewPing _Ultrasonic;

public:
   ULTRASONIC_CONTROL(int maxDistance = 200);

   unsigned int getMM(); // Return distance value in 'mm'
};

class IR_SENSOR_CONTROL
{
private:
   int _reference;

public:
   IR_SENSOR_CONTROL(int reference = 500);

   int IR_Check(); // Return IR State
};

#endif