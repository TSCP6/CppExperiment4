#include "ExecutorImpl.hpp"
#include "Command.hpp"

#include <memory>
#include <new>

namespace adas {
//: pose(pose) assign the param pose with current pose
ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {
}

// const means that don't change the member variables
Pose ExecutorImpl::Query(void) const noexcept {
    return poseHandler.Query();
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
        if (cmd == 'M') {
            // use unique pointer for MoveCommand instantiation, don't worry about delete
            //  std::unique_ptr<MoveCommand>cmder = std::make_unique<MoveCommand>();
            cmder = std::make_unique<MoveCommand>();
            //*this is the instantiated object
        } else if (cmd == 'L') {
            // std::unique_ptr<MoveCommand> Mcmder = std::make_unique<MoveCommand>();
            // std::unique_ptr<TurnLeftCommand>Lcmder = std::make_unique<TurnLeftCommand>();
            cmder = std::make_unique<TurnLeftCommand>();
        } else if (cmd == 'R') {
            // std::unique_ptr<MoveCommand> Mcmder = std::make_unique<MoveCommand>();
            // std::unique_ptr<TurnRightCommand> Rcmder = std::make_unique<TurnRightCommand>();
            cmder = std::make_unique<TurnRightCommand>();
        } else if (cmd == 'F') {
            cmder = std::make_unique<FastCommand>();
        }

        if (cmder) {
            cmder->DoOperate(poseHandler);
        }
    }
}

} // namespace adas