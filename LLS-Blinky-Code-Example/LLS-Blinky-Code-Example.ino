/*
 *
 *   Copyright (C) 2022 Erich S. Heinzle
 *   Website https://github.com/Lobethal-Lutheran-School/
 *   
 *   Lobethal Lutheran School - "Historically Grounded, Future Minded"
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License at <http://www.gnu.org/licenses/> 
 *   for more details.
 *
 */

// the code has been uploaded using a USB-ASP programmer 
// and the "USB-ASP slow (Microcore)" setting in the arduino IDE

// here we define the commonly used things as more easily parsed labels
#define LED5 2
#define LED4 1
#define LED3 0
#define LED2 4
#define LED1 3
#define DELAY 300

// microcore does not recognise analogread digital pin nomenclature
#define PROG A0

// here we set up the relevant pins for input and output
void setup() {
 pinMode(0, OUTPUT);
 pinMode(1, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, INPUT);
}

// a routine that cycles from the inner LED
// to the outer ring of LEDs after DELAY microseconds
void innerOuter() {
 digitalWrite(LED5, HIGH); // turn the LED on (HIGH is the voltage level)
 digitalWrite(LED2, HIGH);
 digitalWrite(LED1, HIGH);
 digitalWrite(LED3, HIGH);
 delay(DELAY);
 digitalWrite(LED5, LOW);
 digitalWrite(LED2, LOW);
 digitalWrite(LED1, LOW);
 digitalWrite(LED3, LOW);
 digitalWrite(LED4, HIGH);
 delay(DELAY);
 digitalWrite(LED4, LOW);
}

// a routine that cycles through the LEDs one at a time
// moving to the next LED after DELAY microseconds
void oscarChaser() {
 digitalWrite(LED5, HIGH); // turn the LED on (HIGH is the voltage level)
 delay(DELAY);             // wait for DELAY microseconds
 digitalWrite(LED5, LOW); // turn the LED off (LOW is the voltage level)
 delay(DELAY);
 digitalWrite(LED2, HIGH);
 delay(DELAY);
 digitalWrite(LED2, LOW);
 delay(DELAY);
 digitalWrite(LED4, HIGH);
 delay(DELAY);
 digitalWrite(LED4, LOW);
 delay(DELAY);
 digitalWrite(LED1, HIGH);
 delay(DELAY);
 digitalWrite(LED1, LOW);
 delay(DELAY);
 digitalWrite(LED3, HIGH);
 delay(DELAY);
 digitalWrite(LED3, LOW);
 delay(DELAY);

}

// a routine that keeps the LED on 'tenths' microseconds every ten microseconds
// to achieve 10 steps in the level of brightness for all LEDS 
void LEDbrightness(int tenths) {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  delay(tenths);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  delay(10-tenths);
}

// a routine that ramps the LED brightness up, then down repeatedly
void oscarPulse() {
  int i, j;
  for (i = 1; i <= 10; i++) {
    for (j = 0; j < 25; j++) {
      LEDbrightness(i);
    }
  }
  for (i = 10; i > 0; i--) {
    for (j = 0; j < 25; j++) {
      LEDbrightness(i);
    }
  }
}

// this routine returns a number 1,2 or 3, depending
// on which of the top three jumpers is selected.
// NB, the lower jumper will put the MCU into reset unless a
// value for R4 is chosen that is at least three times
// that of R1-R3. The if/then/else code would then need
// to be modified to refine the thresholds and add the
// additional return option 
int getJumperOption() {
  int progval = analogRead(A0);
  if (progval > 900) {
    return 1;
  } else if (progval > 800) {
    return 2;
  } else {
    return 3;
  }
}

// you can add more routines here, limited only by your imagination
// and the available memory in your microcontroller

// the main loop which calls the LED lighting code
void loop() {
  switch (getJumperOption()) {
    case 1:
      oscarPulse();
      break;
    case 2:
      innerOuter();
      break;
    case 3:
      oscarChaser();
      break;
  }
}
