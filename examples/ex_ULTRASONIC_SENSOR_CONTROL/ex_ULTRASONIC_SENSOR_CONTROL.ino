/*
   [EDU CAR Shield Rev 5.0] Ultrasonic Sensor Control Example
      - Created by MAKIST (SEOKMIN KANG)
      - Created Date : 2024.05.26
      - Last Update : 2024.05.26
*/

#include <MakistCar.h>

MakistCar myCar;

void setup()
{
   Serial.begin(115200);
   myCar.pinInit();
}

void loop()
{
   unsigned int distanceMM = myCar.getMM();

   if (distanceMM > 0)
   {
      if (Serial)
      {
         Serial.print("ULTRASONIC DISTANCE: ");
         Serial.print(distanceMM);
         Serial.println("mm");
      }
   }
   delay(50);
}
