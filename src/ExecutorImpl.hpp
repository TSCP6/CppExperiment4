#pragma once

#include "Executor.hpp"
#include <string>

namespace adas {
// Detail executor implementation
class ExecutorImpl final : public Executor { // public child class, final means can't be inherited
  public:
    // constructor
    explicit ExecutorImpl(const Pose &pose) noexcept;
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
    class ICommand {
      public:
        virtual ~ICommand() = default;
        virtual void DoOperate(ExecutorImpl &ExecutorImpl) const noexcept = 0 ;
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

  private:
    // private member: pose of car
    Pose pose;

    // is fasten speed
    bool isFast;

    // move function
    void Move(void) noexcept;

    // turn functions
    void TurnLeft(void) noexcept;

    void TurnRight(void) noexcept;
};
} // namespace adas