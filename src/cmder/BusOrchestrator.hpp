#pragma once

#include "NormalOrchestrator.hpp"

namespace adas {
class BusOrchestrator : public NormalOrchestrator {
  public:
    ActionGroup TurnLeft(const PoseHandler &poseHandler) const noexcept override {
        ActionGroup actionGroup;

        actionGroup += OnFast(poseHandler);

        actionGroup.PushAction(GetStepAction(poseHandler));

        actionGroup.PushAction(poseHandler.IsReverse() ? ActionType::REVERSE_TURN_LEFT_ACTION
                                                       : ActionType::TURNLEFT_ACTION);

        return actionGroup;
    }

    ActionGroup TurnRight(const PoseHandler &poseHandler) const noexcept override {
        ActionGroup actionGroup;

        actionGroup += OnFast(poseHandler);

        actionGroup.PushAction(GetStepAction(poseHandler));

        actionGroup.PushAction(poseHandler.IsReverse() ? ActionType::REVERSE_TURN_RIGHT_ACTION
                                                       : ActionType::TURNRIGHT_ACTION);

        return actionGroup;
    }
};

} // namespace adas
