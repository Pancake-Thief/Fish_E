#ifndef MEASURE_FLOW_RATE_HPP
#define MEASURE_FLOW_RATE_HPP

namespace FlowRate{
    //Measures the flow rate
    class FlowRateMetric{
    public:
        //Constructor for flow rate metric object
        FlowRateMetric(int pinIn);

        //Returns the Flow Rate in liters a minute
        float getFlowRate();
    private:
        //Helper function that gets the Frequency of the sensor
        float getFrequency();

        //Pin input for the sensor
        int mPinIn;
    };
}

#endif