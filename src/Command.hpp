#pragma once

#include "ExecutorImpl.hpp"

namespace adas {
class ICommand {
  public:
    virtual ~ICommand() = default;
    virtual void DoOperate(ExecutorImpl &ExecutorImpl) const noexcept = 0;
};

class FastCommand final : public ICommand {
  public:
    virtual void DoOperate(ExecutorImpl &executor) const noexcept override {
        executor.Fast();
    }
};

// define a nested class
class MoveCommand final : public ICommand {
  public:
    // operating move function needs ExecutorImpl& executor
    void DoOperate(ExecutorImpl &executor) const noexcept override {
        executor.Move();
    }
};

class TurnLeftCommand final : public ICommand {
  public:
    // operating move function needs ExecutorImpl& executor
    void DoOperate(ExecutorImpl &executor) const noexcept override {
        executor.TurnLeft();
    }
};

class TurnRightCommand final : public ICommand {
  public:
    // operating move function needs ExecutorImpl& executor
    void DoOperate(ExecutorImpl &executor) const noexcept override {
        executor.TurnRight();
    }
};
} // namespace adas