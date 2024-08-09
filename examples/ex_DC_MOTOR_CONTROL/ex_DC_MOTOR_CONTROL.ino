/*
   [EDUCAR Shield Rev6.0] DC Motor Control Example
      - Created by MAKIST (S.M KANG)
      - Created Date : 2024.05.26
      - Last Update : 2024.07.18
*/

#include <MakistCar.h>

MakistCar myCar;

void setup()
{
   myCar.pinInit();
   delay(500);

   // Motor Control
   myCar.speed(255); // Forward Speed(PWM): 255
   delay(5000);
   myCar.speed(-255); // Reverse Speed(PWM): 255
   delay(1000);
   myCar.speed(0); // Stop
   delay(1000);

   // Left Motor Control
   myCar.leftSpeed(255); // Forward Speed(PWM): 255
   delay(5000);
   myCar.leftSpeed(-255); // Reverse Speed(PWM): 255
   delay(1000);
   myCar.leftSpeed(0); // Stop
   delay(1000);

   // Right Motor Control
   myCar.rightSpeed(255); // Forward Speed(PWM): 255
   delay(5000);
   myCar.rightSpeed(-255); // Reverse Speed(PWM): 255
   delay(1000);
   myCar.rightSpeed(0); // Stop
   delay(1000);
}

void loop()
{
}
