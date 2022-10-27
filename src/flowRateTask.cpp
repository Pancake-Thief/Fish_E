#include "flowRateTask.hpp"
#include "measureFlowRate.hpp"

#include <Arduino.h>

//Init task parameters
static const char *name = "flowRateTask";
static const int priority = tskIDLE_PRIORITY;
static const uint32_t stackSize = 4096;

static int pinIn = 0;

//Constructor
Fish::FlowRateTask::FlowRateTask()
    : Task(name, priority, stackSize){}

void Fish::FlowRateTask::start(int pinIn1){
    pinIn = pinIn1;
    xTaskCreate(taskFunction, myName, myStackSize, this, myPriority, nullptr);
}

void Fish::FlowRateTask::taskFunction(void *task){
    //Fish::FlowRateTask* flowRateTask = static_cast<Fish::FlowRateTask *>(task);
    //flowRateTask->setup();
    //flowRateTask->loop();
    //Setup temporary solution
    FlowRate::FlowRateMetric flowRate = FlowRate::FlowRateMetric(pinIn);

    //Loop temp solution
    while(1){
        float waterMin = flowRate.getFlowRate();
        Serial.println(waterMin);
    }
}

/*void Fish::FlowRateTask::setup(){
    //Add code here
    static FlowRate::FlowRateMetric flowRate = FlowRate::FlowRateMetric(pinIn);
    
}

void Fish::FlowRateTask::loop(){
    while(1){
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        float dutyCycle = flowRate.getFlowRate();
        Serial.println(dutyCycle);
    }
}*/