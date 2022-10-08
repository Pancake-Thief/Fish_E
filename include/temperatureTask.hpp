#ifndef TEMPERATURE_TASK_HPP
#define TEMPERATURE_TASK_HPP

#include "task.hpp"

namespace Fish{
    class TemperatureTask: public Task{
    public:
        //Constructor of Temperature Task object
        TemperatureTask();

        //Executes the task by calling xTaskCreate
        void start(int pinIn) override;

    private:
        //Overarching function that calls setup() and loop()
        static void taskFunction(void *task);

        //Setup function for task before loop()
        //Do not call outside of taskFunction()
        void setup();

        //Loop function that runs forever
        //Do not call outside of taskFunction()
        void loop();
    };
}
#endif