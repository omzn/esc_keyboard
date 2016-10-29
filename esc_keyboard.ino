#define RXLED_PIN (17)
#define KEY_PIN   ( 2)

#define PRESSED   ( 1)
#define RELEASED  ( 0)

uint8_t esc_pressed;

void setup() {
  pinMode(KEY_PIN,   INPUT_PULLUP);
  pinMode(RXLED_PIN, OUTPUT);
  Keyboard.begin();
  esc_pressed = RELEASED;
}

void loop() {
  uint8_t is_keypress = digitalRead(KEY_PIN);
  // RXLED lights then pin is 0
  digitalWrite(RXLED_PIN, 1 - esc_pressed);
  if (is_keypress == LOW && esc_pressed == RELEASED) {
    Keyboard.press(KEY_ESC);
    esc_pressed = PRESSED;
  } else if (is_keypress == HIGH && esc_pressed == PRESSED) {
    Keyboard.release(KEY_ESC);
    esc_pressed = RELEASED;
  }
  delay(1);
}
