#include <Arduino.h>

#include "flowRateTask.hpp"
#include "temperatureTask.hpp"

#define VERSION "0.0.1"

void setup() {
  Serial.begin(115200);
  log_i("Version: %s", VERSION);
  Fish::TemperatureTask temperatureTask;
  Fish::FlowRateTask flowRateTask;

  flowRateTask.start(22);
  temperatureTask.start(23);
  // put your setup code here, to run once:
}

void loop() {
  // Have things done in the tasks
}