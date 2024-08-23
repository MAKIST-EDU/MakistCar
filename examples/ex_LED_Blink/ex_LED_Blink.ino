/*
   [EDUCAR Shield Rev5.0] Linetracing Basic Example
      - Created by MAKIST (S.M KANG)
      - Created Date : 2024.05.26
      - Last Update : 2024.07.19

    -------------------------------- [Caution] -------------------------------------
    1. Check the ESP32 Board version (recommended version 3.0.)
    --------------------------------------------------------------------------------

*/

#include <MakistCar.h>

MakistCar myCar;

void setup() {
  myCar.pinInit();
}

void loop() {
  myCar.ledOn();
  delay(1000);
  myCar.ledOff();
  delay(1000);
}
