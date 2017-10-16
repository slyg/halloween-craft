#define PIN_LED_R 2
#define PIN_LED_G 1
#define PIN_LED_B 0
#define PIN_SENSOR 4

void initLed() {
  digitalWrite(PIN_LED_R, HIGH);
  analogWrite(PIN_LED_G, 0);
  analogWrite(PIN_LED_B, 0);
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
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  pinMode(PIN_SENSOR, INPUT);
  initLed();
}

void enlightmentCycle() {
  fadeVal(PIN_LED_G, 0, 255, 3);
  fadeVal(PIN_LED_B, 0, 255, 3);
  fadeVal(PIN_LED_B, 255, 0, 1);
  fadeVal(PIN_LED_G, 255, 0, 1);
}

int greenValue = 0;

void loop() {
  if (digitalRead(PIN_SENSOR) == HIGH) {
    enlightmentCycle();
    greenValue = 0;
  } else {
    int nextGreenValue = random(0, 10);
    fadeVal(PIN_LED_G, greenValue, nextGreenValue, 20);
    greenValue = nextGreenValue;
  }
}