// SoftwareSerial allows us to see any digital pins for serial communication
// this frees up pins 0 and 1 (hardware serial) for USB/Serial Monitor debugging
#include <SoftwareSerial.h>

// Pin setup
//Connect Bluetooth TX -> Arduino pin 2
//Connect Bluetooth RX -> Arduino pin 3
const int BT_RX_PIN = 2; // Arduino receives data from Bluetooth TX 
const int BT_TX_PIN = 3; // Arduino sends data to Bluetooth RX

// Baud rate
//make sure this matches the Bluetooth module's configured baud rate
//most HC-05/HC-06 modules default to 9600
const long BT_BAUD = 9600;

// Command characters
//these must match whatever the bluetooth controller app is sending
const char CMD_FORWARD  = 'F';
const char CMD_BACKWARD = 'B';
const char CMD_LEFT     = 'L';
const char CMD_RIGHT    = 'R';
const char CMD_STOP     = 'S';

// Bluetooth object
//creates a software-based serial port on pins 2 and 3
// args: (RX pin, TX pin)
SoftwareSerial bluetooth(BT_RX_PIN, BT_TX_PIN);
