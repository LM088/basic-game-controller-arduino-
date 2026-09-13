int button1 = 0; // Left (Pin 2)
int button2 = 0; // Right (Pin 4)
int button3 = 0; // Up (Pin 6)
int button4 = 0; // Down (Pin 7)

int lastButton1 = LOW;
int lastButton2 = LOW;
int lastButton3 = LOW;
int lastButton4 = LOW;

void setup() {
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  pinMode(12, OUTPUT); // Status LED Left
  pinMode(13, OUTPUT); // Status LED Right

  Serial.begin(115200); // Fast baud rate for low latency
}

void loop() {
  button1 = digitalRead(2);
  button2 = digitalRead(4);
  button3 = digitalRead(6);
  button4 = digitalRead(7);

  // Left Button (Pin 2)
  if (button1 == HIGH && lastButton1 == LOW) {
    Serial.print("L");
    digitalWrite(12, HIGH);
  } else if (button1 == LOW) {
    digitalWrite(12, LOW);
  }

  // Right Button (Pin 4)
  if (button2 == HIGH && lastButton2 == LOW) {
    Serial.print("R");
    digitalWrite(13, HIGH);
  } else if (button2 == LOW) {
    digitalWrite(13, LOW);
  }

  // Up Button (Pin 6)
  if (button3 == HIGH && lastButton3 == LOW) {
    Serial.print("U");
  }

  // Down Button (Pin 7)
  if (button4 == HIGH && lastButton4 == LOW) {
    Serial.print("D");
  }

  // Save states for next loop iteration
  lastButton1 = button1;
  lastButton2 = button2;
  lastButton3 = button3;
  lastButton4 = button4;

  delay(5); // Debounce delay
}