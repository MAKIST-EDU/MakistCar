#include "Arduino.h"
#include "MakistCar.h"

// DC MOTOR CONTROL
DC_Motor_Control::DC_Motor_Control(int Forward_Pin, int Reverse_Pin, int pwmFreq, int pwmResolution)
    : _Forward_Pin(Forward_Pin), _Reverse_Pin(Reverse_Pin)
{
   ledcAttach(_Forward_Pin, pwmFreq, pwmResolution);
   ledcAttach(_Reverse_Pin, pwmFreq, pwmResolution);
}

void DC_Motor_Control::Speed(int Forward, int Reverse)
{
   ledcWrite(_Forward_Pin, Forward);
   ledcWrite(_Reverse_Pin, Reverse);
}

void DC_Motor_Control::Stop_N()
{
   Speed(0, 0);
}

void DC_Motor_Control::Stop_B()
{
   Speed(200, 200);
}

// SERVO MOTOR CONTROL
SERVO_MOTOR_CONTROL::SERVO_MOTOR_CONTROL(int Center_Angle, int Max_Angle)
    : _Center_Angle(Center_Angle), _Max_Angle(Max_Angle)
{

   _servo.attach(SERVO_PIN);
}

void SERVO_MOTOR_CONTROL::write(int value)
{
   if (value < 180 && value > 0)
      _servo.write(value);
}

void SERVO_MOTOR_CONTROL::Angle(int value)
{
   if (value < 180 && value > 0)
      _servo.write(value);
}

void SERVO_MOTOR_CONTROL::Handle(char value)
{
   if (value == 'C')
      _servo.write(_Center_Angle);
   else if (value == 'R')
      _servo.write(_Center_Angle + _Max_Angle);
   else if (value == 'L')
      _servo.write(_Center_Angle - _Max_Angle);
}

// ULTRASONIC SENSOR CONTROL
ULTRASONIC_CONTROL::ULTRASONIC_CONTROL(int maxDistance)
    : _Ultrasonic(TRIG_PIN, ECHO_PIN, maxDistance)
{
   pinMode(TRIG_PIN, OUTPUT);
   pinMode(ECHO_PIN, INPUT);
}

unsigned int ULTRASONIC_CONTROL::getMM()
{
   unsigned int us = _Ultrasonic.ping();
   return (us * 10) / 58.0;
}

// IR SENSOR CONTROL
IR_SENSOR_CONTROL::IR_SENSOR_CONTROL(int reference)
    : _reference(reference)
{
   pinMode(IR1_PIN, INPUT);
   pinMode(IR2_PIN, INPUT);
   pinMode(IR3_PIN, INPUT);
   pinMode(IR4_PIN, INPUT);
}

int IR_SENSOR_CONTROL::IR_Check()
{
   int IR1 = analogRead(IR1_PIN);
   int IR2 = analogRead(IR2_PIN);
   int IR3 = analogRead(IR3_PIN);
   int IR4 = analogRead(IR4_PIN);

   int state = (IR1 < _reference ? 1 : 0) << 3 |
               (IR2 < _reference ? 1 : 0) << 2 |
               (IR3 < _reference ? 1 : 0) << 1 |
               (IR4 < _reference ? 1 : 0);
   return state;
}
