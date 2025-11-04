#include "ExecutorImpl.hpp"
// #include "Command.hpp"
#include "CmderFactory.hpp"
#include "Singleton.hpp"

#include <algorithm>
// #include <unordered_map>
// #include <memory>
// #include <new>

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
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);

    std::for_each(
        cmders.begin(),
        cmders.end(),
        [this](const std::function<void(PoseHandler &poseHandler)> &cmder) noexcept {
            cmder(poseHandler);
        }
    );
}
} // namespace adas