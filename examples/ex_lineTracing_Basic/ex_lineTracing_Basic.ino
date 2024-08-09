/*
   [EDUCAR Shield Rev5.0] Linetracing Basic Example
      - Created by MAKIST (S.M KANG)
      - Created Date : 2024.05.26
      - Last Update : 2024.07.19

    -------------------------------- [Caution] -------------------------------------
    1. Check the ESP32 Board version (recommended version 3.0.)
    2. Verify library installation.
      - Servo Motor Library: ESP32Servo (by Kevin Harrington...)
    --------------------------------------------------------------------------------

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
  int ir_value = myCar.irCheck(); // check range 0 ~ 15

  switch (ir_value)
  {
  case 0: // 0000 : No line detected
    myCar.handle('C');
    myCar.speed(200); // Motor Speed Control : object(PWM)
    break;
  case 1: // 0001 : Right edge line detected
    myCar.handle('L');
    myCar.speed(100);
    break;
  case 2: // 0010
    break;
  case 3: // 0011
    break;
  case 4: // 0100
    break;
  case 5: // 0101
    break;
  case 6: // 0110
    break;
  case 7: // 0111
    break;
  case 8: // 1000 : Left edge line detected
    myCar.handle('R');
    myCar.speed(100);
    break;
  case 9: // 1001
    break;
  case 10: // 1010
    break;
  case 11: // 1011
    break;
  case 12: // 1100
    break;
  case 13: // 1101
    break;
  case 14: // 1110
    break;
  case 15: // 1111 : All sensors detect lines
    myCar.handle('C');
    myCar.speed(0);
    break;
  default:
    break;
  }
}
