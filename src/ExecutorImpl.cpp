#include "ExecutorImpl.hpp"

#include <new>

namespace adas {
//: pose(pose) assign the param pose with current pose
ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose) {
}

// const means that don't change the member variables
Pose ExecutorImpl::Query(void) const noexcept {
    return pose;
}

// this method creates and returns a new ExecutorImpl object
Executor *Executor::NewExecutor(const Pose &pose) noexcept {
    return new (std::nothrow) ExecutorImpl(pose); // only valid under C++17
    // std::nothrow is a const to indicate that don't throw error when allocating memory
    // it's usually used in namespace new and std::nothrow
    // it returns null ptr instead of std::bad_alloc error
}

void ExecutorImpl::Execute(const std::string &commands) noexcept {
    for (const auto cmd : commands) {
        if (cmd == 'M') {
            if (pose.heading == 'E')
                ++pose.x;
            else if (pose.heading == 'W')
                --pose.x;
            else if (pose.heading == 'N')
                ++pose.y;
            else if (pose.heading == 'S')
                --pose.y;
        } else if (cmd == 'L') {
            if (pose.heading == 'E')
                pose.heading = 'N';
            else if (pose.heading == 'W')
                pose.heading = 'S';
            else if (pose.heading == 'N')
                pose.heading = 'W';
            else if (pose.heading == 'S')
                pose.heading = 'E';
        } else if (cmd == 'R') {
            if (pose.heading == 'E')
                pose.heading = 'S';
            else if (pose.heading == 'W')
                pose.heading = 'N';
            else if (pose.heading == 'N')
                pose.heading = 'E';
            else if (pose.heading == 'S')
                pose.heading = 'W';
        }
    }
}
} // namespace adas