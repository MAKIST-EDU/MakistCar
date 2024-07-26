/*
   [EDUCAR Shield Rev5.0] Linetracing Basic Example
      - Created by MAKIST (S.M KANG)
      - Created Date : 2024.05.26
      - Last Update : 2024.07.19 

    -------------------------------- [Caution] -------------------------------------
    1. Check the ESP32 Board version (recommended version 2.0.17)
    2. Verify library installation.
      - Servo Motor Library: ESP32Servo (by Kevin Harrington...)
      - Ultrasonic Sensor Library: NewPing (by Tim Eckel)
    --------------------------------------------------------------------------------

*/

#include <MakistCar.h>
IR_SENSOR_CONTROL ir(35, 34, 39, 36, 500);  //object(IR1 pin, IR2, IR3, IR4, reference)
SERVO_MOTOR_CONTROL servo(16, 90, 35);      //object(pin no, angle, max angle)
DC_Motor_Control lMotor(2, 4, 6, 7);        //object(forward pin, reverse pin, forward channel, reverse channel)
DC_Motor_Control rMotor(13, 27, 8, 9);

void setup() {
  Serial.begin(115200);
}

void loop() {
  int ir_value = ir.IR_Check();  // check range 0 ~ 15

  switch (ir_value) {
    case 0:  //0000 : No line detected
      servo.Handle('C');
      lMotor.Speed(200, 0);  //Left Motor Speed Control : object(Forward PWM, Reverse PWM)
      rMotor.Speed(200, 0);  //Right Motor Speed Control
      break;
    case 1:  //0001 : Right edge line detected
      servo.Handle('L');
      lMotor.Speed(150, 0);
      rMotor.Speed(200, 0);
      break;
    case 2:  //0010
      break;
    case 3:  //0011
      break;
    case 4:  //0100
      break;
    case 5:  //0101
      break;
    case 6:  //0110
      break;
    case 7:  //0111
      break;
    case 8:  //1000 : Left edge line detected
      servo.Handle('R');
      lMotor.Speed(200, 0);
      rMotor.Speed(150, 0);
      break;
    case 9:  //1001
      break;
    case 10:  //1010
      break;
    case 11:  //1011
      break;
    case 12:  //1100
      break;
    case 13:  //1101
      break;
    case 14:  //1110
      break;
    case 15:  //1111 : All sensors detect lines
      servo.Handle('C');
      lMotor.Stop_B();
      rMotor.Stop_B();
      break;
    default:
      break;
  }
}
