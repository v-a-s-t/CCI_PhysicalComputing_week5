// Pin definitions
#define SWITCH 2
#define LED 9
#define BUZZER 5

// The tone frequency the buzzer makes
const int buzzerTone = 5000;

void setup() {
  // Turn on serial communication with the computer
  Serial.begin(9600);
  // Set output pins
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  // Set switch pin as input, with an internal pullup 
  // resistor
  pinMode(SWITCH, INPUT_PULLUP);
}

void loop() {
  // Read value of switch
  int switchValue = digitalRead(SWITCH);
  // Print switch value to serial monitor
  Serial.println(switchValue);

  // If switch is closed, aka low, turn on outputs
  // (normally when a switch is closed, it's HIGH, but 
  // when we use INPUT_PULLUP, it's reversed.)
  if (switchValue == LOW) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, buzzerTone);
  }
  else {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
  }

  // Delay so that we don't overwhelm the serial port
  delay(5);
}
