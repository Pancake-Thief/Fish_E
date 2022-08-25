#include "temperatureTask.hpp"
#include <Arduino.h>

//Vars used for starting the task
static const char *name = "temperatureTask";
static const int priority = 1;
static const uint32_t stackSize = 4096;

//Constructor
Fish::TemperatureTask::TemperatureTask()
    : Task(name, priority, stackSize){}

void Fish::TemperatureTask::start(){
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
        
    }
}