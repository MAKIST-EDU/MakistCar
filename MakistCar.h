#ifndef MakistCar_h
#define MakistCar_h

#include "Arduino.h"
#include <NewPing.h>
#include <ESP32Servo.h>

class DC_Motor_Control {
   private:
      const int _Forward_Pin;
      const int _Reverse_Pin;
      const int _Forward_Channel;
      const int _Reverse_Channel;
   public:
      DC_Motor_Control(int Forward_Pin, int Reverse_Pin, int Forward_Channel, int Reverse_Channel, int pwmFreq = 5000, int pwmResolution = 8);

      void Speed(int Forward, int Reverse);
      void Stop_N(); //Neutral
      void Stop_B(); //Break
};

class SERVO_MOTOR_CONTROL {
   private:
      const int _Servo_Pin;
      const int _Center_Angle;
      const int _Max_Angle;
      Servo _servo;

   public:
      SERVO_MOTOR_CONTROL(int Servo_Pin, int Center_Angle = 90, int Max_Angle = 35);

      void write(int value);
      void Angle(int value);
      void Handle(char value);
};


class ULTRASONIC_CONTROL {
   private:
      const int _TRIG_Pin;
      const int _ECHO_Pin;
      NewPing _Ultrasonic;

   public:
      ULTRASONIC_CONTROL(int TRIG_Pin, int ECHO_Pin, int maxDistance = 200);

      unsigned int getMM(); // Return distance value in 'mm'
};

class IR_SENSOR_CONTROL {
   private:
      const int _IR1_Pin;
      const int _IR2_Pin;
      const int _IR3_Pin;
      const int _IR4_Pin;
      int _reference;
   public:
      IR_SENSOR_CONTROL(int IR1_Pin, int IR2_Pin, int IR3_Pin, int IR4_Pin, int reference = 500);

      int IR_Check(); // Return IR State
};

#endif