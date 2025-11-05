#pragma once

#include "CmderOrchestrator.hpp"
#include "core/PoseHandler.hpp"

#include <functional>

namespace adas {
// class ICommand {
//   public:
//     virtual ~ICommand() = default;
//     virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
// };

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
    ActionGroup operator()(PoseHandler &poseHandler, const CmderOrchestrator& orchestrator) const noexcept {
        // if (poseHandler.IsFast()) {
        //     if (poseHandler.IsReverse()) {
        //         poseHandler.Backward();
        //     } else
        //         poseHandler.Forward();
        // }
        // if(poseHandler.IsReverse()){
        //     poseHandler.Backward();
        // }else{
        //     poseHandler.Forward();
        // }

        // ActionGroup actionGroup;

        // const auto action =
        //     poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;

        // if (poseHandler.IsFast()) {
        //     actionGroup.PushAction(action); // when in fast state, move one more
        // }

        // actionGroup.PushAction(action);

        return orchestrator.Move(poseHandler);
    };
};

class TurnLeftCommand final {
  public:
    // operating move function needs ExecutorImpl& executor
    ActionGroup operator()(PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept {
        return orchestrator.TurnLeft(poseHandler);
    };
};

class TurnRightCommand final {
  public:
    // operating move function needs ExecutorImpl& executor
    ActionGroup operator()(PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept {
        return orchestrator.TurnRight(poseHandler);
    };
};

class FastCommand final {
  public:
    ActionGroup operator()(PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept {
        ActionGroup actionGroup;
        actionGroup.PushAction(ActionType::BE_FAST_ACTION);
        return actionGroup;
    };
};

class ReverseCommand final {
  public:
    ActionGroup operator()(PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept {
        ActionGroup actionGroup;
        actionGroup.PushAction(ActionType::BE_REVERSE_ACTION);
        return actionGroup;
    };
};

class TurnRoundCommand final {
  public:
    ActionGroup operator()(PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept {
        return orchestrator.TurnRound(poseHandler);
    };
};

} // namespace adas