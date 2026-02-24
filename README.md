# Bluetooth Controlled Car — Arduino Project

Welcome to the team! Please read this before you start coding.

---

## Before You Start

If you are struggling with the code, **please check the documentation first** before asking for help or making changes. Most common issues are already answered there.

---

## Documentation & References

### Arduino
- **SoftwareSerial Library** — https://docs.arduino.cc/learn/built-in-libraries/software-serial/
- **AFMotor Library (Adafruit Motor Shield)** — https://learn.adafruit.com/adafruit-motor-shield/library-reference
- **Serial Communication** — https://docs.arduino.cc/language-reference/en/functions/communication/serial/
- **General Arduino Reference** — https://docs.arduino.cc/language-reference/

### Bluetooth Module (HC-05 / HC-06)
- **HC-05 Setup Guide** — https://projecthub.arduino.cc/
- Default baud rate is **9600** unless you have manually changed it

## Common Mistakes to Avoid

- **Wrong baud rate** — make sure your code and Bluetooth module use the same baud rate (`9600` by default)
- **Missing `Serial.available()` check** — always check if data is available before reading from Serial
- **`#include` not at the top** — all `#include` statements must be at the very first lines of your file
- **Pins 0 & 1 conflict** — avoid using pins 0 and 1 for Bluetooth as they are shared with USB, use SoftwareSerial on pins 2 & 3 instead

---

## Team Reminders

> If you are unsure about something, **check the documentation first.**
> If the documentation does not answer your question, then ask a teammate.
> Do not change working code without informing the rest of the team.

---

## Recommended Tools

| Tool | Purpose | Link |
|------|---------|------|
| Arduino IDE | Compile & upload code | https://www.arduino.cc/en/software |
| Wokwi | Simulate Arduino online | https://wokwi.com |
| GitHub Gist | Share code snippets | https://gist.github.com |

---

*Last updated: February 2026*
