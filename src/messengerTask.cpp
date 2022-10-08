#include "messengerTask.hpp"

#include <Arduino.h>

//Init task parameters
static const char *name = "messengerTask";
static const int priority = 2;
static const uint32_t stackSize = 4096;

//Constructor
Fish::MessengerTask::MessengerTask() :
    Task(name, priority, stackSize){}

void Fish::MessengerTask::start(int pinIn){
    this->pinIn = pinIn;
    xTaskCreate(taskFunction, myName, myStackSize, this, myPriority, nullptr);
}

void Fish::MessengerTask::taskFunction(void *task){
    //Setup

    //Loop
    while(1){
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

/*void Fish::MessengerTask::setup(){

}

void Fish::MessengerTask::loop(){
    while(1){
    }
}*/