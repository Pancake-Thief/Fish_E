#include "flowRateTask.hpp"
#include <Arduino.h>

//Init task parameters
static const char *name = "flowRateTask";
static const int priority = 1;
static const uint32_t stackSize = 4096;

static const int pinIn = 22;

//COnstructor
Fish::FlowRateTask::FlowRateTask()
    : Task(name, priority, stackSize){}

void Fish::FlowRateTask::start(){
    xTaskCreate(taskFunction, myName, myStackSize, this, myPriority, nullptr);
}

void Fish::FlowRateTask::taskFunction(void *task){
    Fish::FlowRateTask* flowRateTask = static_cast<Fish::FlowRateTask *>(task);
    flowRateTask->setup();
    flowRateTask->loop();
}

void Fish::FlowRateTask::setup(){
    //Add code here
}

void Fish::FlowRateTask::loop(){
    while(1){
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        log_i("Hello from Flow Rate Task");
        Serial.println("Hello from Flow Rate Task");
        float On = pulseIn(pinIn, HIGH);
        float Off = pulseIn(pinIn, LOW);
        float Total = On + Off;
        float dutyCycle = (On) / Total;
        Serial.println(dutyCycle);
    }
}