// Submitted by Jeremiah

// The HC-SR04 works by emitting short ultrasonic pulse (40kHz) from thee TRIG pin,
// then measuring how long it make for echo to return on the ECO pin.
// Using the speed of sound, we can convert hat travel time into a distance measurement.

// Pin definitions
// TRIG (Trigger): Output pin that sends the ultrasonic pulse
// ECHO: Input pin that receives the reflected pulse
const int trigPin = 9;
const int echoPin = 10;

// Variables
// duration: raw travel time of the sound wave (in microseconds)
// distance: calculated distance to the detected object (in cm)
long duration;
int distance;

void setup() {
  // configure TRIG as output, we will drive it HIGH/LOW to fire pulses
  pinMode(trigPin, OUTPUT);

  //configure ECHO as input, the sensor drives this HIGH for as long as it takes the echo to return
  pinMode(echoPin, INPUT);

  // start serial communication at 9600 baud so we can print
  // readings to the Serial Monitor (Tools > Serial Monitor)
  Serial.begin(9600);
}

void loop() {
  // reset the trigger pin
  
  // ensure TRIG starts LOW so we get a clean pulse with no noise
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // brief setting time before firing

  // send the ultrasonic pulse
  
  // driving TRIG HIGH for exactly 10µs (microseconds) tekks the HC-SR04 to fire a burst of 8 ultrasonic pulses at 40kHz
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // pulse must be at least 10 microseconds
  digitalWrite(trigPin, LOW; // end the trigger pulse

  // measure the echo duration
  
  // pulseIn() waits for ECHO to go HIGH, then measures how long it stays HIGH, this is the total round-trip travel time
  duration = pulseIn(echoPin, HIGH);

  // convert time to distance
  
  // speed of sound ≈ 0.034 cm/µs at room temperature.
  // we divide by 2 because the pulse travels TO the object AND back, so we only want half the total distance.
  //  distance (cm) - duration (µs) x 0.034 (cm/µs) / 2
  distance = duration * 0.034 / 2;

  // output the result

  // print the calculated distance to the Arduino Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.printIn(" cm";
}
