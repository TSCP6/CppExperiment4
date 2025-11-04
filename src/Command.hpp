#pragma once

#include "PoseHandler.hpp"

#include <functional>

namespace adas {
// class ICommand {
//   public:
//     virtual ~ICommand() = default;
//     virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
// };

class FastCommand final {
  public:
    void operator()(PoseHandler &poseHandler) const noexcept {
        poseHandler.Fast();
    };
};

// define a nested class
class MoveCommand final {
  public:
    // operating move function needs ExecutorImpl& executor
    // void DoOperate(PoseHandler &poseHandler) const noexcept override {
    //     if (poseHandler.IsFast()) {
    //         poseHandler.Move();
    //     }
    //     poseHandler.Move();
    // }
    // const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept {
    //     if (poseHandler.IsFast()) {
    //         poseHandler.Move();
    //     }
    //     poseHandler.Move();
    // };
    void operator()(PoseHandler &poseHandler) const noexcept {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.Move();
    };
};

class TurnLeftCommand final {
  public:
    // operating move function needs ExecutorImpl& executor
    void operator()(PoseHandler &poseHandler) const noexcept {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.TurnLeft();
    };
};

class TurnRightCommand final {
  public:
    // operating move function needs ExecutorImpl& executor
    void operator()(PoseHandler &poseHandler) const noexcept {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.TurnRight();
    };
};
} // namespace adas