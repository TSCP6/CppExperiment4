#pragma once

// #include "Executor.hpp"
#include "core/PoseHandler.hpp"
#include "cmder/CmderOrchestrator.hpp"

// #include <string>
#include <memory>

namespace adas {
// Detail executor implementation
class ExecutorImpl final : public Executor { // public child class, final means can't be inherited
  public:
    // constructor
    explicit ExecutorImpl(const Pose &pose, CmderOrchestrator* orchestrator) noexcept;
    // only create ExecutorImpl object explicitly
    // Pose p{1,2,'E'}; ExecutorImpl a(p) (correct); ExecutorImpl b = p (Error)

    // destructor
    ~ExecutorImpl() noexcept = default;

    // can't copy
    ExecutorImpl(const ExecutorImpl &) = delete;

    // can't assign
    ExecutorImpl &operator=(const ExecutorImpl &) = delete;

  public:
    // query the pose of car, the detail implementation of parent Query method
    Pose Query(void) const noexcept override;

    void Execute(const std::string &command) noexcept override;

  private:
    PoseHandler poseHandler; //状态管理类
    std::unique_ptr<CmderOrchestrator> orchestrator;
};
} // namespace adas