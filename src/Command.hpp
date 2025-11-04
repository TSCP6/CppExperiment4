#pragma once

#include "ActionGroup.hpp"
#include "PoseHandler.hpp"

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
    ActionGroup operator()(PoseHandler &poseHandler) const noexcept {
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

        ActionGroup actionGroup;

        const auto action =
            poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;

        if (poseHandler.IsFast()) {
            actionGroup.PushAction(action); // when in fast state, move one more
        }

        actionGroup.PushAction(action);

        return actionGroup;
    };
};

class TurnLeftCommand final {
  public:
    // operating move function needs ExecutorImpl& executor
    ActionGroup operator()(PoseHandler &poseHandler) const noexcept {
        ActionGroup actionGroup;

        const auto action =
            poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;

        const auto turnLeft =
            poseHandler.IsReverse() ? ActionType::REVERSE_TURN_LEFT_ACTION : ActionType::TURNLEFT_ACTION;

        if (poseHandler.IsFast()) {
            actionGroup.PushAction(action);
        }
        actionGroup.PushAction(turnLeft);

        return actionGroup;
    };
};

class TurnRightCommand final {
  public:
    // operating move function needs ExecutorImpl& executor
    ActionGroup operator()(PoseHandler &poseHandler) const noexcept {
        ActionGroup actionGroup;

        const auto action =
            poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;

        const auto turnRight =
            poseHandler.IsReverse() ? ActionType::REVERSE_TURN_RIGHT_ACTION : ActionType::TURNRIGHT_ACTION;

        if (poseHandler.IsFast()) {
            actionGroup.PushAction(action);
        }
        actionGroup.PushAction(turnRight);

        return actionGroup;
    };
};

class FastCommand final {
  public:
    ActionGroup operator()(PoseHandler &poseHandler) const noexcept {
        ActionGroup actionGroup;
        actionGroup.PushAction(ActionType::BE_FAST_ACTION);
        return actionGroup;
    };
};

class ReverseCommand final {
  public:
    ActionGroup operator()(PoseHandler &poseHandler) const noexcept {
        ActionGroup actionGroup;
        actionGroup.PushAction(ActionType::BE_REVERSE_ACTION);
        return actionGroup;
    };
};

class TurnRoundCommand final {
  public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept{
        if(poseHandler.IsReverse()){
            return ActionGroup();
        }
        else{
            if(poseHandler.IsFast()){
                return ActionGroup({
                    ActionType::FORWARD_1_STEP_ACTION,
                    ActionType::TURNLEFT_ACTION,
                    ActionType::FORWARD_1_STEP_ACTION,
                    ActionType::TURNLEFT_ACTION,
                });
            }
            else{
                return ActionGroup({
                    ActionType::TURNLEFT_ACTION,
                    ActionType::FORWARD_1_STEP_ACTION,
                    ActionType::TURNLEFT_ACTION,
                });
            }
        }
    };
};

} // namespace adas