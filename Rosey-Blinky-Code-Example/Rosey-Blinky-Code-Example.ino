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
#define LED2 4
#define LED1 3
#define DELAY 15

// used for the morse code
#define DIT_MS 80

// on the Rosey PCB, there are only 2 LEDs used
// freeing up the pins needed for a pogo pin
// based pogo pin fixture
void setup() {
 pinMode(1, OUTPUT);
 pinMode(2, OUTPUT);
}

void LEDbrightness(int tenths) {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  delay(tenths);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(10-tenths);
}

// hypnotising dog eyes
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

void dit(int dit_ms) {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  delay(dit_ms);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(dit_ms);  
}

void dah(int dit_ms) {
  int dah_ms = dit_ms*3;
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  delay(dah_ms);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(dit_ms);  
}

// subliminal messaging for food
void oscarFUD(int dit_ms) {
  dit(dit_ms);
  dit(dit_ms);
  dah(dit_ms);
  dit(dit_ms);
  delay(3*dit_ms);
  dit(dit_ms);
  dit(dit_ms);
  dah(dit_ms);
  delay(3*dit_ms);
  dah(dit_ms);
  dit(dit_ms);
  dit(dit_ms);
  delay(7*dit_ms);  
}

// the main loop which calls the LED lighting code
void loop() {
  oscarPulse();
  delay(1000);
  oscarFUD(DIT_MS);
  delay(1000);
}
