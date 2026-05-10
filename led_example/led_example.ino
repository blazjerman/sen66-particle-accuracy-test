#define RED_LED    13
#define GREEN_LED  2
#define BLUE_LED   32

void setRGB(bool red, bool green, bool blue) {
  digitalWrite(RED_LED, red ? HIGH : LOW);
  digitalWrite(GREEN_LED, green ? HIGH : LOW);
  digitalWrite(BLUE_LED, blue ? HIGH : LOW);
}

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  setRGB(false, false, false);
}

void loop() {
  // Red
  setRGB(true, false, false);
  delay(500);

  // Green
  setRGB(false, true, false);
  delay(500);

  // Blue
  setRGB(false, false, true);
  delay(500);

  // Yellow: red + green
  setRGB(true, true, false);
  delay(500);

  // Purple: red + blue
  setRGB(true, false, true);
  delay(500);

  // Cyan: green + blue
  setRGB(false, true, true);
  delay(500);

  // White: red + green + blue
  setRGB(true, true, true);
  delay(500);

  // Off
  setRGB(false, false, false);
  delay(500);
}