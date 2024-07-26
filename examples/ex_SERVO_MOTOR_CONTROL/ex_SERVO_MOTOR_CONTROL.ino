/*
   [EDUCAR Shield Rev5.0] Servo Motor Control Example
      - Created by MAKIST (S.M KANG)
      - Created Date : 2024.05.26
      - Last Update : 2024.07.19 
   
   -------------------------------- [Caution] -------------------------------------
       Add library before using the Servo Motor (see usage below)
         1. Open Library Manager
         2. Search for 'ESP32Servo'
         3. Install 'ESP32Servo by Kevin H...' Version 3.0.5
            - No need to include the library manually.

      ** Install the ESP32 Board Manager version 2.0.17. 
         If version 3.0 of the Board Manager is installed, it needs to be downgraded.
   --------------------------------------------------------------------------------
*/

#include <MakistCar.h>

SERVO_MOTOR_CONTROL servo(16, 90, 35); //object(pin no, angle, max angle)


void setup() {
   delay(2000);
   servo.write(90);
   delay(1000);
   servo.Handle('L');
   delay(1000);
   servo.Handle('C');
   delay(1000);
   servo.Handle('R');
}

void loop() {
  // put your main code here, to run repeatedly:
}
