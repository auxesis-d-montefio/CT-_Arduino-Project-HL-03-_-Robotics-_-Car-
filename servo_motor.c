#include <Servo.h>        // Includes the Servo library to control servo motors
#include <NewPing.h>      // Includes the ultrasonic sensor library (HC-SR04)

#define TRIG_PIN 6        // Trigger pin of ultrasonic sensor
#define ECHO_PIN 7        // Echo pin of ultrasonic sensor
#define MAX_DISTANCE 250  // Maximum distance to measure (in cm)

Servo myservo;            // Create servo object
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);  // Create sonar object

void setup() {
  myservo.attach(9);      // Attach servo signal wire to pin 9
  myservo.write(115);     // Set servo to center position (115 degrees)
  delay(2000);            // Wait 2 seconds for servo to stabilize
}

void loop() {
  // Example usage (optional testing)
  int rightDistance = lookRight();
  delay(1000);

  int leftDistance = lookLeft();
  delay(1000);
}

int lookRight() {
  myservo.write(50);      // Rotate servo to right
  delay(500);             // Wait for servo to reach position

  int d = readPing();     // Measure distance
  myservo.write(115);     // Return to center position

  return d;               // Return measured distance
}

int lookLeft() {
  myservo.write(170);     // Rotate servo to left
  delay(500);             // Wait for servo to reach position

  int d = readPing();     // Measure distance
  myservo.write(115);     // Return to center position

  return d;               // Return measured distance
}

int readPing() {
  delay(70);              // Short delay for sensor stability

  int cm = sonar.ping_cm();  // Get distance in centimeters

  if (cm == 0) {          // If no object detected
    cm = 250;             // Set to max distance (failsafe)
  }

  return cm;              // Return distance value
}
