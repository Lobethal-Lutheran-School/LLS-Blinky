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

#define LED5 2
#define LED4 1
#define LED3 0
#define LED2 4
#define LED1 3
#define DELAY 300

void setup() {
 pinMode(0, OUTPUT);
 pinMode(1, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, INPUT);
}

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

void loop() {
  oscarPulse();
}
