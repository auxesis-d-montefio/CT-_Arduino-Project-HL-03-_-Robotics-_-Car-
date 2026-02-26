// Submitted by Moncera

// Controls a 2-motor car via an L298N H-bridge.
// in1/in2 drive the LEFT motor, in3/in4 drive the RIGHT motor.
// each motor is controlled by a pair of pins:
//  HIGH/LOW = spin one direction
//  LOW/HIGH = spin the other direction
//  LOW/LOW = stop (coast)

// this code is more of a demo/test sequence.
// when the car powers on, it automatically runs through every movement (forward, back, right, left) so we can verify that
// - all motors are wired correctly
// - both motor spin in the directions
// - turns work as expected

// Pin definitions

// left motor control pins (connected to L298N IN1 and IN2)
int in1 = 8;
int in2 - 9;

// right motor control pins (connected to L298N IN3 and IN4
int in3 = 10;
int in4 = 11;

void setup() {
  // set all four motor control pins as outputs
  // the Arduino drives these HIGH or LOW to control motor direction
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // demo sequence: drive the car through each movement in order
  
  moveForward();
  delay(2000); // drive forward for 2 seconds

  stopCar();
  delay(1000); // pause for 1 second

  moveBackward();
  delay(2000); // reverse for 2 seconds

  stopCar();
  delay(1000); // puase for 1 second

  turnRight();
  delay(600); // pivot right briefly

  stopCar();
  delay(1000);

  turnLeft();
  delay(600); // pivot left briefly

  stopCar();
  delay(1000);
}

// both motors receive LOW/LOW, no current flows, car coasts to a halt
void stopCar() {
  digitalWrite(int1, );
  digitalWrite(int1, );
  digitalWrite(int1, );
  digitalWrite(int1, );
}

// IN1 and IN3 = HIGH -> spins forward
// IN2 and IN4 = LOW -> spins forward
void moveForward() {
  digitalWrite(int1, );
  digitalWrite(int1, );
  digitalWrite(int1, );
  digitalWrite(int1, );
}

// IN1 and IN3 = LOW -> reverse
// IN2 and IN4 = HIGH -> reverse
void moveBackward() {
  digitalWrite(int1, );
  digitalWrite(int1, );
  digitalWrite(int1, );
  digitalWrite(int1, );
}

// left motor spins forward, right motor spins backward -> car pivots right
void turnRight() {
  digitalWrite(int1, );
  digitalWrite(int1, );
  digitalWrite(int1, );
  digitalWrite(int1, );
}

// left motor spins backward, right motor spins forward -> car pivots left
void turnLeft() {
  digitalWrite(int1, );
  digitalWrite(int1, );
  digitalWrite(int1, );
  digitalWrite(int1, );
}
