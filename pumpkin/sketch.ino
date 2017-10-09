#define PIN_R 0
#define PIN_B 2
#define PIN_G 1


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);

  analogWrite(PIN_R, 255);
  analogWrite(PIN_G, 0);
  analogWrite(PIN_B, 0);
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

int greenValue = 255;

void loop() {
  int nextGreenValue = random(20, 200);
  int period = random(0, 10);
  fadeVal(PIN_G, greenValue, nextGreenValue, period);
  greenValue = nextGreenValue;
}
