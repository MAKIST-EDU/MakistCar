/*
   [EDU CAR Shield Rev 5.0] IR Sensor Check Example
      - Created by MAKIST (SEOKMIN KANG)
      - Created Date : 2024.05.26
      - Last Update : 2024.08.23


   IR_SENSOR_CONTROL.IR_Check() - return value table
   ================================================================================
   * IR Sensor Check Value (White = 1 , black = 0)
   --------------------------------------------------------------------------------
   Sensor      IR1         IR2         IR3         IR4         return value
   Position    Right Out   Right In    Left In     Left Out
               0           0           0           0           0
               0           0           0           1           1
               0           0           1           0           2
               0           0           1           1           3
               0           1           0           0           4
               0           1           0           1           5
               0           1           1           0           6
               0           1           1           1           7
               1           0           0           0           8
               1           0           0           1           9
               1           0           1           0           10
               1           0           1           1           11
               1           1           0           0           12
               1           1           0           1           13
               1           1           1           0           14
               1           1           1           1           15
   ================================================================================
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
   int irValue = myCar.irCheck(); // Check the 4 IR sensors. IR1,IR2,IR3,IR4
   // int irValue = myCar.irSideCheck(); // Check the 2 IR sensors. IR1,IR4
   // int irValue = myCar.irMidCheck(); //Check the 2 IR sensors. IR2,IR3

   if (Serial)
   {
      Serial.print("IR STATE : ");
      Serial.println(irValue); // Output IR sensor measurement value from 0 to 4 or 0 to 15
   }
   delay(100);
}
