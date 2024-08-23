<h1>MAKIST CAR for ESP32</h1>
This library is for simple control of makist car.

<h2>Installation</h2>
1. In the Arduino IDE, navigate to Sketch > Include Library > Manage Libraries
2. Then the Library Manager will open and you will find a list of libraries that are already installed or ready for installation.
3. Then search for MAKISTCAR using the search bar.
4. Click on the text area and then select the specific version and install it.

<h2>Functions</h2>
<ul>
<li>pinInit(int pwmFreq = 5000, int pwmResolution = 8)</li>
<li>ledOn()</li>
<li>ledOff()</li>
<li>direction()</li>
<li>speed(int speed)</li>
<li>leftSpeed(int speed)</li>
<li>rightSpeed(int speed)</li>
<li>servoWrite(int value)</li>
<li>servoAngle(int value)</li>
<li>handleOffset(int _centerAngle, int _maxAngle)</li>
<li>handle(char value)</li>
<li>getMM()</li>
<li>setMaxDistance(unsigned int max_cm_distance)</li>
<li>pingTrigger()</li>
<li>int irCheck(int reference = 500)</li>
<li>int irSideCheck(int reference = 500)</li>
<li>int irMidCheck(int reference = 500)</li>
</ul>
 * Please refer to the manual for a detailed explanation of the function.  
   
<h2>MAKIST CAR Description</h2>
This is a teaching tool that allows all age groups, including elementary, middle, high school, college students, and adults, to learn coding easily and funly.
Currently, many schools in Korea are hosting competitions using this teaching aid.  
If you are curious about MAKIST CAR, please contact us.
</br >email : makist.biz@gmail.com   
   
<h2>License</h2>
Copyright (c) 2024 MAKIST. All right reserved.
This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software.

