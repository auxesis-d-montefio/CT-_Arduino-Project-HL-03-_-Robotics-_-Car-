// Pin definitions
const int TRIG_PIN = 9;
const int ECHO_PIN = 8;

// Constants
const float SOUND_SPEED_CM_US = 0.034; // Speed of sound in cm/microsecond
const int TIMEOUT_US = 30000;          // Timeout in microseconds (~5m max range)
const int SAMPLE_DELAY_MS = 500;       // Delay between readings

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW); // Ensure trig starts LOW
  Serial.begin(9600);
}

void loop() {
  int distance = measureDistance();

  if (distance < 0) {
    Serial.println("Error: No echo received (out of range)");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(SAMPLE_DELAY_MS);
}

// Sends a trigger pulse and returns the measured distance in cm
// Returns -1 if no echo is received within the timeout
int measureDistance() {
  // Send a clean 10us trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo duration with timeout 
  long duration = pulseIn(ECHO_PIN, HIGH, TIMEOUT_US);

  if (duration == 0) return -1; // Timeout occurred

  return duration * SOUND_SPEED_CM_US / 2;
}
