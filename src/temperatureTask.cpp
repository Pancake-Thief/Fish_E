#include "temperatureTask.hpp"
#include <Arduino.h>

//Vars used for starting the task
static const char *name = "temperatureTask";
static const int priority = 1;
static const uint32_t stackSize = 4096;

//Constructor
Fish::TemperatureTask::TemperatureTask()
    : Task(name, priority, stackSize){}

void Fish::TemperatureTask::start(int pinIn){
    
    xTaskCreate(taskFunction, myName, myStackSize, this, myPriority, nullptr);
}

void Fish::TemperatureTask::taskFunction(void *task){
    Fish::TemperatureTask * temperatureTask = static_cast<Fish::TemperatureTask *>(task);
    temperatureTask->setup();
    temperatureTask->loop();
}

void Fish::TemperatureTask::setup(){
    //Add code for setup
}

void Fish::TemperatureTask::loop(){
    //Add code for loop
    while(1){
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1000 milliseconds
        log_i("Hello from Temperature Task");
        Serial.println("Hello from Temperature Task");
    }
}