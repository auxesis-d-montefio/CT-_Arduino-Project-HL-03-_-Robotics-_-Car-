#include <AFMotor.h>
 
// Motor setup
// initialize 4 DC motors on the Adafruit Motor Shield (port 1-4)
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// Bluetooth command varaible
// stores the last received bluetooth command
// defauls is "S" (Stop) so the car doesnt move on startup
char bt = 'S';

// fnction declaration
void forward();
void backward();
void left();
void right();
void Stop();

void setup() {
    //NOTE: make sure the bluetooth module (e.g. HC-05/HC-06) is also configured to 9600 baud.
    //most modules default to 9600. if you changed the module's baud rate to 38400, change this to match.
    Serial.begin(9600);

    //set all motors to full speed (0-255)
    //speed can be lowered (e.g. 180) if the car moves too fast
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);

    //make sure car is stopped when powered on
    Stop();
}

void loop() {
    //only read from Serial if data is actually available.
    //without this check, Serial.read() returns -1 when idle, which can cause unintended behavior.
    if (Serial.available() > 0) {
        bt = Serial.read();
    }
}

//execute the corresponding movement based on received command
//using else-if so only one command runs per loop cycle

if (bt=='F') {
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

// Movement function

void forward() {
    // all motors spin forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void backward() {
    // all motors spin backward
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void left() {
    // left wheels go backward, right wheels go forward
    // assumes motor 1 and 2 = right side, motor 3 and 4 = left side
    // swap FORWARD/BACKWARD here if the car turns the wrong way
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void right() {
    // left wheels go forward, right wheels go backward
    // assumes motor 1 and 2 = right side, motor 3 and 4 = left side
    // swap FORWARD/BACKWARD here if the car turns the wrong way
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void Stop() {
    // RELEASE cuts power to all motors, letting the car coast to a stop
    // this is the correct way to stop motors with the Adafruit Motor Shield
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}




