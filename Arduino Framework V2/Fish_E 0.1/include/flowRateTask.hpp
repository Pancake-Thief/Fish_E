#ifndef FLOW_RATE_TASK_HPP
#define FLOW_RATE_TASK_HPP

#include "task.hpp"

namespace Fish{
    //This task measures the flow rate of the water using a Hall Sensor
    class FlowRateTask : public Task{
    public:
        //Constructor of task object
        FlowRateTask();

        //Execution of flow rate task calls xTaskCreate
        void start() override; // Override the virtual function in task class

    private:
        //Function that is called by FreeRTOS xTaskCreate()
        //Calls setup() and loop()
        static void taskFunction(void *task);

        //Setup the Flow Rate Task before going on to the loop
        //Do not call outside of the taskFunction()
        void setup();

        //Loop inside of the Flow Rate Task.
        //Do not call outside of taskFunction()
        void loop();

    };
}

#endif