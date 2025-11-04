#pragma once

#include "PoseHandler.hpp"

namespace adas {
class ICommand {
  public:
    virtual ~ICommand() = default;
    virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
};

class FastCommand final : public ICommand {
  public:
    virtual void DoOperate(PoseHandler& poseHandler) const noexcept override {
        poseHandler.Fast();
    }
};

// define a nested class
class MoveCommand final : public ICommand {
  public:
    // operating move function needs ExecutorImpl& executor
    void DoOperate(PoseHandler &poseHandler) const noexcept override {
        if(poseHandler.IsFast()){
            poseHandler.Move();
        }
        poseHandler.Move();
    }
};

class TurnLeftCommand final : public ICommand {
  public:
    // operating move function needs ExecutorImpl& executor
    void DoOperate(PoseHandler &poseHandler) const noexcept override {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.TurnLeft();
    }
};

class TurnRightCommand final : public ICommand {
  public:
    // operating move function needs ExecutorImpl& executor
    void DoOperate(PoseHandler &poseHandler) const noexcept override {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.TurnRight();
    }
};
} // namespace adas