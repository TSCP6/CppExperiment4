#include "ExecutorImpl.hpp"

#include <new>

namespace adas{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept {}

    //const means that don't change the member variables
    Pose ExecutorImpl::Query(void) const noexcept{
        return pose;
    }

    //this method creates and returns a new ExecutorImpl object 
    Executor *Executor::NewExecutor(const Pose &pose) noexcept{
        return new(std::nothrow) ExecutorImpl(pose); //only valid under C++17
        //std::nothrow is a const to indicate that don't throw error when allocating memory
        //it's usually used in namespace new and std::nothrow
        //it returns null ptr instead of std::bad_alloc error
    }
}