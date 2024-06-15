#include <Arduino.h>

void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  
  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);
}

void loop() {
  // ADC 2 is used by wifi
  // see: https://blog.mjyai.com/2022/10/28/esp32-arduino-ads1115-adc-benchmark/
  int analogVolts = analogReadMilliVolts(36);
  int analogVolts2 = analogReadMilliVolts(39);
  int analogVolts3 = analogReadMilliVolts(34);
  int analogVolts4 = analogReadMilliVolts(35);
  int analogVolts5 = analogReadMilliVolts(32);
  int analogVolts6 = analogReadMilliVolts(33);
  
  // print out the values you read:
  Serial.printf("ADC millivolts value = %d %d %d %d %d %d\n", analogVolts, analogVolts2, analogVolts3, analogVolts4, analogVolts5, analogVolts6);
  
  delay(100);  // delay in between reads for clear read from serial
}
