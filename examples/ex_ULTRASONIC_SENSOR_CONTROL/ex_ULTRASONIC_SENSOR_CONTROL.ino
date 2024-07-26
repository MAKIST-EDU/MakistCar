/*
   [EDU CAR Shield Rev 5.0] Ultrasonic Sensor Control Example
      - Created by MAKIST (SEOKMIN KANG)
      - Created Date : 2024.05.26
      - Last Update : 2024.05.26

   -------------------------------- [Caution] -------------------------------------
       Add library before using the ultrasonic sensor (see usage below)
         1. Open Library Manager
         2. Search for 'NewPing'
         3. Install 'NewPing by Tim Eckel'
            - No need to include the library manually.
   --------------------------------------------------------------------------------
*/

#include <MakistCar.h>

//ultrasonic Pin Setting
const int trig_Pin = 32;
const int echo_Pin = 23;

ULTRASONIC_CONTROL ultrasonic(trig_Pin, echo_Pin); // Create ultrasonic sensor object

void setup() {
  Serial.begin(115200);
}

void loop() {
   // Store the distance measured by the ultrasonic sensor in millimeters.
   unsigned int distanceMM = ultrasonic.getMM();

   if(distanceMM > 0){
      if(Serial) {
         Serial.print("ULTRASONIC DISTANCE: ");
         Serial.print(distanceMM);
         Serial.println("mm");
      }
   }

   delay(50);
}
