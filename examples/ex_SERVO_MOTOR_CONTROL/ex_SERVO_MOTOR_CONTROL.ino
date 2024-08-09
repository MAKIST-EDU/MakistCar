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

      ** Install the ESP32 Board Manager version 3.0.
   --------------------------------------------------------------------------------
*/

#include <MakistCar.h>

MakistCar myCar;

void setup()
{
   myCar.pinInit();

   delay(500);
   myCar.servoWrite(90);
   delay(1000);
   myCar.servoWrite(60);
   delay(1000);
   myCar.servoWrite(120);
   delay(1000);
}

void loop()
{
   myCar.handleOffset(90, 35);
   myCar.handle('C');
   delay(1000);
   myCar.handle('R');
   delay(1000);
   myCar.handle('L');
   delay(1000);

   myCar.handleOffset(100, 10);
   myCar.handle('C');
   delay(1000);
   myCar.handle('R');
   delay(1000);
   myCar.handle('L');
   delay(1000);
}
