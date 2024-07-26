/*
   [EDUCAR Shield Rev5.0] DC Motor Control Example
      - Created by MAKIST (S.M KANG)
      - Created Date : 2024.05.26
      - Last Update : 2024.07.18 

      ** Install the ESP32 Board Manager version 2.0.17. 
         If version 3.0 of the Board Manager is installed, it needs to be downgraded.
*/

#include <MakistCar.h>

// DC_Motor_Control Create Object 
DC_Motor_Control Left_Motor(2, 4, 6, 7);  //(Forward pin, Reverse pin, Forward Channel, Reverse Channel)
DC_Motor_Control Right_Motor(13, 27, 8, 9); //(Forward pin, Reverse pin, Forward Channel, Reverse Channel)

void setup() {
   delay(2000);

   //Left Motor Control
   Left_Motor.Speed(255, 0); //Forward Rotation, Speed(PWM): 255
   delay(2000);
   Left_Motor.Stop_B(); //Break Stop
   delay(100);
   Left_Motor.Speed(0, 255); //Reverse Rotation, Speed(PWM): 255
   delay(2000);
   Left_Motor.Stop_N(); //Neutral Stop
   delay(1000);

   //Right Motor Control
   Right_Motor.Speed(255, 0); //Forward Rotation, Speed(PWM): 255
   delay(2000);
   Right_Motor.Stop_B(); //Break Stop
   delay(100);
   Right_Motor.Speed(0, 255); //Reverse Rotation, Speed(PWM): 255
   delay(2000);
   Right_Motor.Stop_N(); //Neutral Stop
   delay(1000);
}

void loop() {
   // The loop() function is not used in this example.
}
