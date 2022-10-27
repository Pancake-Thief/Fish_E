#include <Arduino.h>

#include "flowRateTask.hpp"
#include "temperatureTask.hpp"

#define VERSION "0.0.1"

const int pin = 13;

void setup() {
  Serial.begin(115200);
  log_i("Version: %s", VERSION);
  pinMode(pin, INPUT);
  //Fish::TemperatureTask temperatureTask;
  Fish::FlowRateTask flowRateTask;

  
  flowRateTask.start(13); //GPIO 18
  //flowRateTask.start(38); //GPIO 19
  //temperatureTask.start(23);
  // put your setup code here, to run once:
}

void loop() {
  vTaskDelete(NULL);
  // Have things done in the tasks
}