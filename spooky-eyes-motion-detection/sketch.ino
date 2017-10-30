#define PIN_LED 0
#define PIN_SENSOR 4

unsigned const MIN = 0;
unsigned const MAX = 255;

void initLed() {
  analogWrite(PIN_LED, 0);
}

void fadeVal(int pin, int startVal, int endVal, int period) {
  if (startVal < endVal) {
    for (int i = startVal; i <= endVal; i++) {
      analogWrite(pin, i);
      delay(period);
    }
  } else {
    for (int j = endVal; j <= startVal; j++) {
      analogWrite(pin, map(j, startVal, endVal, endVal, startVal));
      delay(period);
    }
  }
}


void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_SENSOR, INPUT);
  initLed();
}

unsigned int ledVal = MIN;

void loop() {
  if (digitalRead(PIN_SENSOR) == HIGH) {
    if (ledVal == MIN) {
      fadeVal(PIN_LED, MIN, MAX, 1);
      ledVal = MAX;
    }
  } else {
    if (ledVal == MAX) {
      fadeVal(PIN_LED, MAX, MIN, 1);
      ledVal = MIN;
    }
  }
  delay(1000);
}
