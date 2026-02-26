// Submitted by Jaime
#include <AFMotor.h>

// Code Synopsis: Constant Brake/Active Brake
// ---instead of the usual 'coast' brake wherein all electricity is stopped from entering the motors,
// ---and let it still be moving until friction eventually stops it,
// ---a 'constant' brake releases high voltage that puts the wheels in an immediate stop.

// Motor setup
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char bt = 'S';

void setup() {
    Serial.begin(9600);

    // Initial stop
    Stop();
}

void loop() {
    if (Serial.available() > 0) {
        bt = Serial.read();
    }

    if (bt == 'F') {
        forward();
    } else if (bt == 'B') {
        backward();
    } else if (bt == 'L') {
        left();
    } else if (bt == 'R') {
        right();
    } else if (bt == 'S') {
        Stop();
    }
}

// --- Movement Functions ---

void forward() {
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void backward() {
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void left() {
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void right() {
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void Stop() {
    // Setting speed to 0 makes a CONSTANT BRAKE instead of a COAST BRAKE
    motor1.setSpeed(0);
    motor2.setSpeed(0);
    motor3.setSpeed(0);
    motor4.setSpeed(0);
    
    // We keep them in a "run" state to maintain the electric brake effect
    motor1.run(BRAKE);
    motor2.run(BRAKE);
    motor3.run(BRAKE);
    motor4.run(BRAKE);
}