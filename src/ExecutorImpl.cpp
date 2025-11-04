#include "ExecutorImpl.hpp"
#include "Command.hpp"

#include <unordered_map>
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
    std::unordered_map<char, std::unique_ptr<ICommand>> cmderMap;
    
    //finish the map between command and operator
    cmderMap.emplace('M', std::make_unique<MoveCommand>());
    cmderMap.emplace('L', std::make_unique<TurnLeftCommand>());
    cmderMap.emplace('R', std::make_unique<TurnRightCommand>());
    cmderMap.emplace('F', std::make_unique<FastCommand>());

    for (const auto cmd : commands) {
        const auto it = cmderMap.find(cmd);

        if (it != cmderMap.end()) { //search failure returns end
            //first to key, second to value
            it->second->DoOperate(poseHandler);
        }
    }
}
} // namespace adas