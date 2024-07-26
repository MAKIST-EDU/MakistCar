/*
   [EDU CAR Shield Rev 5.0] IR Sensor Check Example
      - Created by MAKIST (SEOKMIN KANG)
      - Created Date : 2024.05.26
      - Last Update : 2024.05.26

   ================================= [Caution] =================================
       Add library before using the ultrasonic sensor (see usage below)
         1. Open Library Manager
         2. Search for 'NewPing'
         3. Install 'NewPing by Tim Eckel'
            - No need to include the library manually.
   =============================================================================


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

const int IR1 = 36; //Right out
const int IR2 = 39; //Right in
const int IR3 = 34; //left in
const int IR4 = 35; //leftout
const int reference = 500; // IR sensor line reference value (values below this are considered as line)

IR_SENSOR_CONTROL irState(36, 39, 34, 35, reference); // (ir1 pin, ir2 pin, ir3 pin, ir4 pin, line reference value)

void setup() {
   Serial.begin(115200);
}

void loop() {
   int ir_value = irState.IR_Check();

   if(Serial){
      Serial.print("IR STATE : ");
      Serial.println(ir_value); // Output IR sensor measurement value from 0 to 15
   }
   delay(100);
}
