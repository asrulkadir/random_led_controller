int ledPins[] = {2, 3, 4, 5, 6}; // LED pin numbers
int buttonPin = 7; // Push button pin number

bool ledState[] = {false, false, false, false, false};
int ledCount = sizeof(ledPins) / sizeof(int);

int previousButtonState = HIGH; // Push button is normally HIGH (assuming it's connected to GND with a pullup resistor)
int pressCount = 0;

void setup() {
  // Initialize LED pins as output
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Ensure all LEDs are off at the start
  }

  // Initialize push button pin as input
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Check if button has just been pressed
  if (buttonState == LOW && previousButtonState == HIGH) {
    // Increment the button press count and reset if it exceeds the number of LEDs
    pressCount = (pressCount % ledCount) + 1;

    int index;
    do {
      // Get a random LED index
      index = random(0, ledCount);
    } while (ledState[index]); // Ensure the selected LED hasn't been lit already

    // Turn on the selected LED and update its state
    digitalWrite(ledPins[index], HIGH);
    ledState[index] = true;

    delay(100); // Debounce delay
  }
  // Check if button has just been released
  else if (buttonState == HIGH && previousButtonState == LOW) {
    // Turn off all LEDs if button has been pressed the number of LEDs times
    if (pressCount == ledCount) {
      for (int i = 0; i < ledCount; i++) {
        digitalWrite(ledPins[i], LOW);
        ledState[i] = false; // Reset all LED states
      }

      pressCount = 0; // Reset the press count
    } else {
      // Otherwise, turn off the LEDs that were turned on
      for (int i = 0; i < ledCount; i++) {
        if (ledState[i]) {
          digitalWrite(ledPins[i], LOW);
        }
      }
    }

    delay(100); // Debounce delay
  }

  previousButtonState = buttonState; // Save the current button state for the next loop iteration
}

