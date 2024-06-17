#include <Arduino.h>
#include "main.h"
#include "comm.h"
#include <lwip/sockets.h>

int err_cnt[10];

void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  
  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);

  comm_init();
}

void loop() {
  // ADC 2 is used by wifi
  // see: https://blog.mjyai.com/2022/10/28/esp32-arduino-ads1115-adc-benchmark/
  uint16_t analog[6];
  analog[0] = analogRead(36);
  analog[1] = analogRead(39);
  analog[2] = analogRead(34);
  analog[3] = analogRead(35);
  analog[4] = analogRead(32);
  analog[5] = analogRead(33);

  // Serial.printf("%hu %hu %hu %hu %hu %hu\n", analog[0], analog[1], analog[2], analog[3], analog[4], analog[5]);
  
  for (int i = 0; i < 6; ++i) analog[i] = htons(analog[i]);
  comm_send_blocking(COMM_TYPE_FEEDBACK, (uint8_t *)analog);

  delay(10);
}
