#include "ExecutorImpl.hpp"
// #include "Command.hpp"
#include "cmder/BusOrchestrator.hpp"
#include "cmder/CmderFactory.hpp"
#include "cmder/NormalOrchestrator.hpp"
#include "cmder/SportsCarOrchestrator.hpp"
#include "core/Singleton.hpp"

#include <algorithm>
// #include <unordered_map>
// #include <memory>
// #include <new>

namespace adas {
// const means that don't change the member variables
Pose ExecutorImpl::Query(void) const noexcept {
    return poseHandler.Query();
}

// this method creates and returns a new ExecutorImpl object
Executor *Executor::NewExecutor(const Pose &pose, const ExecutorType executorType) noexcept {
    CmderOrchestrator *orchestrator = nullptr;
    switch (executorType) {
    case ExecutorType::NORMAL: {
        orchestrator = new (std::nothrow) NormalOrchestrator();
        break;
    }
    case ExecutorType::BUS: {
        orchestrator = new (std::nothrow) BusOrchestrator();
        break;
    }
    case ExecutorType::SPORTS_CAR: {
        orchestrator = new (std::nothrow) SportsCarOrchestrator();
        break;
    }
    default:
        break;
    }

    return new (std::nothrow) ExecutorImpl(pose, orchestrator); // only valid under C++17
    // std::nothrow is a const to indicate that don't throw error when allocating memory
    // it's usually used in namespace new and std::nothrow
    // it returns null ptr instead of std::bad_alloc error
}

//: pose(pose) assign the param pose with current pose
ExecutorImpl::ExecutorImpl(const Pose &pose, CmderOrchestrator *orchestrator) noexcept
    : poseHandler(pose), orchestrator(orchestrator) {
}

void ExecutorImpl::Execute(const std::string &commands) noexcept {
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);

    std::for_each(cmders.begin(), cmders.end(),
                  [this](const Cmder &cmder) noexcept { cmder(poseHandler, *orchestrator).DoOperate(poseHandler); });
}
} // namespace adas