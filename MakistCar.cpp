#include "Arduino.h"
#include "MakistCar.h"

// DC MOTOR CONTROL
DC_Motor_Control::DC_Motor_Control(int Forward_Pin, int Reverse_Pin, int Forward_Channel, int Reverse_Channel, int pwmFreq, int pwmResolution)
    : _Forward_Pin(Forward_Pin), _Reverse_Pin(Reverse_Pin), _Forward_Channel(Forward_Channel), _Reverse_Channel(Reverse_Channel)
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
SERVO_MOTOR_CONTROL::SERVO_MOTOR_CONTROL(int Servo_Pin, int Center_Angle, int Max_Angle)
    : _Servo_Pin(Servo_Pin), _Center_Angle(Center_Angle), _Max_Angle(Max_Angle)
{

   _servo.attach(_Servo_Pin);
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
ULTRASONIC_CONTROL::ULTRASONIC_CONTROL(int TRIG_Pin, int ECHO_Pin, int maxDistance)
    : _TRIG_Pin(TRIG_Pin), _ECHO_Pin(ECHO_Pin), _Ultrasonic(TRIG_Pin, ECHO_Pin, maxDistance)
{

   pinMode(_TRIG_Pin, OUTPUT);
   pinMode(_ECHO_Pin, INPUT);
}

unsigned int ULTRASONIC_CONTROL::getMM()
{
   unsigned int us = _Ultrasonic.ping();
   return (us * 10) / 58.0;
}

// IR SENSOR CONTROL
IR_SENSOR_CONTROL::IR_SENSOR_CONTROL(int IR1_Pin, int IR2_Pin, int IR3_Pin, int IR4_Pin, int reference)
    : _IR1_Pin(IR1_Pin), _IR2_Pin(IR2_Pin), _IR3_Pin(IR3_Pin), _IR4_Pin(IR4_Pin), _reference(reference)
{

   pinMode(_IR1_Pin, INPUT);
   pinMode(_IR2_Pin, INPUT);
   pinMode(_IR3_Pin, INPUT);
   pinMode(_IR4_Pin, INPUT);
}

int IR_SENSOR_CONTROL::IR_Check()
{
   int IR1 = analogRead(_IR1_Pin);
   int IR2 = analogRead(_IR2_Pin);
   int IR3 = analogRead(_IR3_Pin);
   int IR4 = analogRead(_IR4_Pin);

   int state = (IR1 < _reference ? 1 : 0) << 3 |
               (IR2 < _reference ? 1 : 0) << 2 |
               (IR3 < _reference ? 1 : 0) << 1 |
               (IR4 < _reference ? 1 : 0);
   return state;
}
