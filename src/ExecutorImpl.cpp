#include "ExecutorImpl.hpp"
#include "Command.hpp"

#include <new>
#include <memory>

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
        std::unique_ptr<ICommand> cmder;
        std::unique_ptr<MoveCommand> Mcmder;
        if (cmd == 'M') {
            //use unique pointer for MoveCommand instantiation, don't worry about delete
            // std::unique_ptr<MoveCommand>cmder = std::make_unique<MoveCommand>();
            cmder = std::make_unique<MoveCommand>();
            if (!fast) {
                //*this is the instantiated object
                cmder->DoOperate(*this);
            } else {
                cmder->DoOperate(*this);
                cmder->DoOperate(*this);
            }
        } else if (cmd == 'L') {
            // std::unique_ptr<MoveCommand> Mcmder = std::make_unique<MoveCommand>();
            // std::unique_ptr<TurnLeftCommand>Lcmder = std::make_unique<TurnLeftCommand>();
            cmder = std::make_unique<TurnLeftCommand>();
            if (!fast) {
                cmder->DoOperate(*this);
            } else {
                Mcmder->DoOperate(*this);
                cmder->DoOperate(*this);
            }
        } else if (cmd == 'R') {
            // std::unique_ptr<MoveCommand> Mcmder = std::make_unique<MoveCommand>();
            // std::unique_ptr<TurnRightCommand> Rcmder = std::make_unique<TurnRightCommand>();
            cmder = std::make_unique<TurnRightCommand>();
            if (!fast) {
                cmder->DoOperate(*this);
            } else {
                Mcmder->DoOperate(*this);
                cmder->DoOperate(*this);
            }
        } else if (cmd == 'F') {
            cmder = std::make_unique<FastCommand>();
            cmder->DoOperate(*this);
        }
    }
}

void ExecutorImpl::Move() noexcept {
    if (pose.heading == 'E') {
        ++pose.x;
    } else if (pose.heading == 'W') {
        --pose.x;
    } else if (pose.heading == 'N') {
        ++pose.y;
    } else if (pose.heading == 'S') {
        --pose.y;
    }
}

void ExecutorImpl::TurnLeft() noexcept {
    if (pose.heading == 'E') {
        pose.heading = 'N';
    } else if (pose.heading == 'W') {
        pose.heading = 'S';
    } else if (pose.heading == 'N') {
        pose.heading = 'W';
    } else if (pose.heading == 'S') {
        pose.heading = 'E';
    }
}

void ExecutorImpl::TurnRight() noexcept {
    if (pose.heading == 'E') {
        pose.heading = 'S';
    } else if (pose.heading == 'W') {
        pose.heading = 'N';
    } else if (pose.heading == 'N') {
        pose.heading = 'E';
    } else if (pose.heading == 'S') {
        pose.heading = 'W';
    }
}

void ExecutorImpl::Fast() noexcept {
    fast = !fast;
}

bool ExecutorImpl::isFast() const noexcept {
    return fast;
}

} // namespace adas