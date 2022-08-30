#ifndef MESSENGER_TASK_HPP
#define MESSENGER_TASK_HPP

#include "task.hpp"

namespace Fish{
    //This task receives data from producer tasks and hands it off to consumer tasks
    //Producers being: flowRateTask, temperatureTask
    //Consumer being: dataHandlerTask
    class MessengerTask : public Task{
    public:
        //Constructor
        MessengerTask();

        //Execution of Messenger Task calls xTaskCreate
        void start() override;

    private:
        //Function that is called by FreeRTOS xTaskCreate()
        //Calls setup() and loop()
        static void taskFunction(void* task);

        //Setup the Messenger Task before going on to the loop
        //Do no call outside of the taskFunction()
        void setup();

        //Loop inside of the Messenger Task.
        //Do not call outside of the taskFunction()
        void loop();
    };
}

#endif