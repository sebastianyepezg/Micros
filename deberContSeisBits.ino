#define btn 7
int i = 0;
int leds[6] = {8, 9, 10, 11, 12, 13};
int cont = 0;
int cont2;
void setup() {
  for (; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(btn, INPUT);
}
void loop() {
  if (digitalRead(btn) == HIGH) {
    cont++;
    if (cont > 0 && cont < 64) {
      cont2 = cont;
      for (int i = 0; i < 6; i++) {
        if (cont2 % 2 == 1) {
          digitalWrite(leds[i], HIGH);
        }
        else {
          digitalWrite(leds[i], LOW);
        }
        cont2 = cont2 / 2;
      }
    }
    else {
      for (i = 0; i < 6; i++) {
        digitalWrite(leds[i], LOW);
      }
      cont = 0;
    }
    delay(300);
  }
}
