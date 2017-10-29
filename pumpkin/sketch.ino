#define PIN_R 0
#define PIN_B 2
#define PIN_G 1


void setup() {
  
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
int blueValue = 0;
int redValue = 0;

void loop() {
  int nextGreenValue = random(0, 255);
  int nextBlueValue = random(0, 255);
  int nextRedValue = random(0, 255);
  int period = random(0, 10);
  fadeVal(PIN_G, greenValue, nextGreenValue, period);
  fadeVal(PIN_G, blueValue, nextBlueValue, period);
  fadeVal(PIN_G, redValue, nextRedValue, period);
  greenValue = nextGreenValue;
}
