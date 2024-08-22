#include "Arduino.h"
#include "MakistCar.h"

// DC MOTOR CONTROL
void MakistCar::pinInit(int pwmFreq, int pwmResolution)
{
   ledcAttach(L_MOTOR_A_PIN, pwmFreq, pwmResolution);
   ledcAttach(L_MOTOR_B_PIN, pwmFreq, pwmResolution);
   ledcAttach(R_MOTOR_A_PIN, pwmFreq, pwmResolution);
   ledcAttach(R_MOTOR_B_PIN, pwmFreq, pwmResolution);

   servo.attach(SERVO_PIN);

   pinMode(IR1_PIN, INPUT);
   pinMode(IR2_PIN, INPUT);
   pinMode(IR3_PIN, INPUT);
   pinMode(IR4_PIN, INPUT);

   pinMode(TRIG_PIN, OUTPUT);
   pinMode(ECHO_PIN, INPUT);

   pinMode(RIGHT_LED_PIN, OUTPUT);
   pinMode(LEFT_LED_PIN, OUTPUT);
}

void MakistCar::direction()
{
   motorDir = motorDir * -1;
}
// DC MOTOR CONTROL
void MakistCar::speed(int speed)
{
   speed = constrain(speed, -100, 100);
   float m = (maxSpeed - minSpeed) / 100.0;
   float b = minSpeed;
   int pwm = m * abs(speed) + b;

   if (speed * motorDir < 0)
   {
      ledcWrite(L_MOTOR_A_PIN, pwm);
      ledcWrite(L_MOTOR_B_PIN, 0);
      ledcWrite(R_MOTOR_A_PIN, pwm);
      ledcWrite(R_MOTOR_B_PIN, 0);
   }
   else if (speed * motorDir > 0)
   {
      ledcWrite(L_MOTOR_A_PIN, 0);
      ledcWrite(L_MOTOR_B_PIN, pwm);
      ledcWrite(R_MOTOR_A_PIN, 0);
      ledcWrite(R_MOTOR_B_PIN, pwm);
   }
   else
   {
      ledcWrite(L_MOTOR_A_PIN, 0);
      ledcWrite(L_MOTOR_B_PIN, 0);
      ledcWrite(R_MOTOR_A_PIN, 0);
      ledcWrite(R_MOTOR_B_PIN, 0);
   }
}

void MakistCar::leftSpeed(int speed)
{
   speed = constrain(speed, -100, 100);
   float m = (maxSpeed - minSpeed) / 100.0;
   float b = minSpeed;
   int pwm = m * abs(speed) + b;

   if (speed * motorDir < 0)
   {
      ledcWrite(L_MOTOR_A_PIN, pwm);
      ledcWrite(L_MOTOR_B_PIN, 0);
   }
   else if (speed * motorDir > 0)
   {
      ledcWrite(L_MOTOR_A_PIN, 0);
      ledcWrite(L_MOTOR_B_PIN, pwm);
   }
   else
   {
      ledcWrite(L_MOTOR_A_PIN, 0);
      ledcWrite(L_MOTOR_B_PIN, 0);
   }
}

void MakistCar::rightSpeed(int speed)
{
   speed = constrain(speed, -100, 100);
   float m = (maxSpeed - minSpeed) / 100.0;
   float b = minSpeed;
   int pwm = m * abs(speed) + b;

   if (speed * motorDir < 0)
   {
      ledcWrite(R_MOTOR_A_PIN, pwm);
      ledcWrite(R_MOTOR_B_PIN, 0);
   }
   else if (speed * motorDir > 0)
   {

      ledcWrite(R_MOTOR_A_PIN, 0);
      ledcWrite(R_MOTOR_B_PIN, pwm);
   }
   else
   {
      ledcWrite(R_MOTOR_A_PIN, 0);
      ledcWrite(R_MOTOR_B_PIN, 0);
   }
}
// SERVO MOTOR CONTROL
void MakistCar::servoWrite(int value)
{
   if (value < 180 && value > 0)
      servo.write(value);
}

void MakistCar::servoAngle(int value)
{
   if (value < 180 && value > 0)
      servo.write(value);
}

void MakistCar::handleOffset(int _centerAngle, int _maxAngle)
{
   centerAngle = _centerAngle;
   maxAngle = _maxAngle;
}

void MakistCar::handle(char value)
{
   if (value == 'C')
      servo.write(centerAngle);
   else if (value == 'R')
      servo.write(centerAngle + maxAngle);
   else if (value == 'L')
      servo.write(centerAngle - maxAngle);
}

// ULTRASONIC SENSOR CONTROL
unsigned int MakistCar::getMM()
{
   setMaxDistance(MAX_DISTANCE);

   if (!pingTrigger())
      return NO_ECHO;

   while (digitalRead(ECHO_PIN))
      if (micros() > maxTime)
         return NO_ECHO;

   return (micros() - (maxTime - maxEchoTime) - PING_OVERHEAD);
}

boolean MakistCar::pingTrigger()
{

   digitalWrite(TRIG_PIN, LOW); // 안정화 대기
   delayMicroseconds(2);
   digitalWrite(TRIG_PIN, HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIG_PIN, LOW);

   if (digitalRead(ECHO_PIN))
      return false;                                     // Previous ping hasn't finished, abort.
   maxTime = micros() + maxEchoTime + MAX_SENSOR_DELAY; // Maximum time we'll wait for ping to start (most sensors are <450uS, the SRF06 can take up to 34,300uS!)

   while (!digitalRead(ECHO_PIN)) // Wait for ping to start.
      if (micros() > maxTime)
         return false; // Took too long to start, abort.

   maxTime = micros() + maxEchoTime; // Ping started, set the time-out.
   return true;                      // Ping started successfully.
}

void MakistCar::setMaxDistance(unsigned int max_cm_distance)
{
   maxEchoTime = min(max_cm_distance + 1, (unsigned int)MAX_SENSOR_DISTANCE + 1) * US_ROUNDTRIP_CM;
}

void MakistCar::irInit(int _irPinSet)
{
   irPinSet = _irPinSet;
}

// IR SENSOR CONTROL
int MakistCar::irCheck(int reference)
{
   if (irPinSet == 2)
   {
      int IR1 = analogRead(IR1_PIN);
      int IR4 = analogRead(IR4_PIN);

      int state = (IR4 < reference ? 1 : 0) << 1 |
                  (IR1 < reference ? 1 : 0);
      return state;
   }
   else
   {
      int IR1 = analogRead(IR1_PIN);
      int IR2 = analogRead(IR2_PIN);
      int IR3 = analogRead(IR3_PIN);
      int IR4 = analogRead(IR4_PIN);

      int state = (IR4 < reference ? 1 : 0) << 3 |
                  (IR3 < reference ? 1 : 0) << 2 |
                  (IR2 < reference ? 1 : 0) << 1 |
                  (IR1 < reference ? 1 : 0);
      return state;
   }
}

void MakistCar::ledOn()
{
   digitalWrite(RIGHT_LED_PIN, HIGH);
   digitalWrite(LEFT_LED_PIN, HIGH);
}
void MakistCar::ledOff()
{
   digitalWrite(RIGHT_LED_PIN, LOW);
   digitalWrite(LEFT_LED_PIN, LOW);
}