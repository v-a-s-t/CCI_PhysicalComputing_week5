// Include capacitive sensor library. Install from 
// libraries manager if you haven't already.
#include <CapacitiveSensor.h>

// Pin definitions
#define C_RECEIVE 4
#define C_SEND 2
#define LED 9
#define BUZZER 5

// Let's define a new capacitive sensor
CapacitiveSensor sensor = CapacitiveSensor(C_SEND, C_RECEIVE);

// Threshold for our buzzer / light to turn on
const long threshold = 10000;
// The tone frequency the buzzer makes
const int buzzerTone = 5000;

void setup() {
  // Turn on serial communication with the computer
  Serial.begin(9600);
  // Set output pins
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // Read value of capacitive sensor
  long value = sensor.capacitiveSensor(30);
  // Print out value on serial monitor
  Serial.println(value);

  // If value is greater than threshold, turn on outputs
  if (value >= threshold) {
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
