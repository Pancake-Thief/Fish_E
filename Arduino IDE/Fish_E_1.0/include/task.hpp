#ifndef TASK_HPP
#define TASK_HPP

#include <FreeRTOS.h>
#include <cstdint>

namespace Fish {
    //Abstract class to inherit for each task
    class Task{
    public:
        //Construct the Task object. Parameters used in RTOS
        // @param name Name of task
        // @param priority Priority number assigned to task
        // @param stackSize Size of stack given to task

        Task(const char *name, const int priority, const uint32_t stackSize) :
            myName(name), myPriority(priority), myStackSize(stackSize){}

        //Execution of task
        virtual void start() = 0; 
    }
}

#endif