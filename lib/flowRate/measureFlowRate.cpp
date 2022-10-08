#include <Arduino.h>

#include "measureFlowRate.hpp"

using namespace FlowRate;

FlowRateMetric::FlowRateMetric(int pinIn) 
    : mPinIn(pinIn)
{}

void FlowRateMetric::printTest(){
    Serial.println("Test");
}

float FlowRateMetric::getFlowRate(){
    //Convert duty cycle to liters per minute
    float Frequency = this->getFrequency();
    float literMin = Frequency / 12;
    return literMin;
}

float FlowRateMetric::getFrequency(){
    float On = pulseIn(this->mPinIn, HIGH);
    float Off = pulseIn(this->mPinIn, LOW);
    return 1000000 / (On + Off);
}