/**
 * @file pin_rotate.ino
 * @brief Arduino sketch to rotate a pin on and off
 *
 * This sketch will rotate all pins of the board on and off. The duration of each pin is 1 second.
 * Following boards are supported:
 * - Arduino Uno
 * - Arduino Leonardo
 * - Arduino M0
 * - Redscorp RP2040-Eins
 * - Redscorp RP2040-ProMini
 * 
 * @date 2023/11/28
 * @version 1.0.0
 */

#include <Arduino.h>

int pins_list[] =
#if defined(ARDUINO_AVR_UNO)
  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5};  // Set the pins for Uno boards
#elif defined(ARDUINO_AVR_LEONARDO)
  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5};  // Set the pins for Leonardo boards
#elif defined(ARDUINO_SAMD_ZERO)
  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5};  // Set the pins for M0 boards
#elif defined(ARDUINO_REDSCORP_RP2040_EINS)
  {D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, A0, A1, A2, A3, D18, D19, D20, D21};  // Set the pins for RP2040-Eins boards
#elif defined(ARDUINO_REDSCORP_RP2040_PROMINI)
  {D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, A0, A1, A2, A3, D18, D19, D20, D21};  // Set the pins for RP2040-ProMini boards
#else
  #error "Unsupported board. Add conditions for the board in the code."
#endif

const int duration = 1000; // 1 second duration for each pin
const int pin_count = sizeof(pins_list) / sizeof(pins_list[0]); // Get the number of pins in the list

void setup() {
  Serial.begin();
  for (int i = 0; i < pin_count; i++) {
    int pin = pins_list[i]; // Get the pin number from the list
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void loop() {
  for (int i = 0; i < pin_count; i++) {
    int pin = pins_list[i]; // Get the pin number from the list
    digitalWrite(pin, HIGH);
    Serial.print("pin: ");
    Serial.print(i);
    Serial.print(" - ");
    Serial.println(pin);
    delay(duration);
    digitalWrite(pin, LOW);
  }
}