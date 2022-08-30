#ifndef DATA_HANDLER_TASK_HPP
#define DATA_HANDLER_TASK_HPP

#include "task.hpp"

namespace Fish{
    //This task would retrieve data from MessengerTask and store it for us to read
    //Current storage/reading: N/A
    //Current options: LCD Screen, IoT, SD Card
    class DataHandlerTask : public Task{
    public:
        //Constructor of task object
        DataHandlerTask();

        //Execution of Data Handler Task
        void start() override;

    private:
        //Function that is called by FreeRTOS xTaskCreate()
        //Calls setup() and loop()
        static void taskFunction(void *task);

        //Set up the Data Handler Task before going in the loop
        //Do not call outside of the taskFunction()
        void setup();

        //Loop inside of the Data Handler Task.
        //Do not call outside of taskFunction()
        void loop();
    };
}

#endif