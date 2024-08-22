/*
   [EDU CAR Shield Rev 5.0] IR Sensor Check Example
      - Created by MAKIST (SEOKMIN KANG)
      - Created Date : 2024.05.26
      - Last Update : 2024.05.26


   IR_SENSOR_CONTROL.IR_Check() - return value table
   ================================================================================
   * IR Sensor Check Value (White = 0 , black = 1)
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
   void irInit(4); // ir 4개 사용 기본 두개
}

void loop()
{
   int ir_value = myCar.irCheck(500);

   if (Serial)
   {
      Serial.print("IR STATE : ");
      Serial.println(ir_value); // Output IR sensor measurement value from 0 to 15
   }
   delay(100);
}
