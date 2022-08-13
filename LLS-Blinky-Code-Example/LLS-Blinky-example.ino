#define LED5 2
#define LED4 1
#define LED3 0
#define LED2 4
#define LED1 3
#define DELAY 300
#define HEARTBEAT 1000

void setup() {
 pinMode(0, OUTPUT);
 pinMode(1, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, INPUT);
}

void oscarChaser() {
 digitalWrite(LED5, HIGH);   // turn the LED on (HIGH is the voltage level)
 delay(DELAY);             // wait for a second
 digitalWrite(LED5, LOW);    // turn the LED off by making the voltage LOW
 delay(DELAY);             // wait for a second
 digitalWrite(LED2, HIGH);   // turn the LED on (HIGH is the voltage level)
 delay(DELAY);             // wait for a second
 digitalWrite(LED2, LOW);    // turn the LED off by making the voltage LOW
 delay(DELAY);             // wait for a second
 digitalWrite(LED4, HIGH);   // turn the LED on (HIGH is the voltage level)
 delay(DELAY);             // wait for a second
 digitalWrite(LED4, LOW);    // turn the LED off by making the voltage LOW
 delay(DELAY);             // wait for a second
 digitalWrite(LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
 delay(DELAY);             // wait for a second
 digitalWrite(LED1, LOW);    // turn the LED off by making the voltage LOW
 delay(DELAY);             // wait for a second
 digitalWrite(LED3, HIGH);   // turn the LED on (HIGH is the voltage level)
 delay(DELAY);             // wait for a second
 digitalWrite(LED3, LOW);    // turn the LED off by making the voltage LOW
 delay(DELAY);             // wait for a second

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
