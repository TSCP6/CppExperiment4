#include "ActionGroup.hpp"
#include "CmderFactory.hpp"

#include <vector>
#include <algorithm>

namespace adas
{
    ActionGroup::ActionGroup(const std::list<ActionType>& actions) noexcept : actions(actions) {

    }

    class ForwardAction final {
        public:
        void operator()(PoseHandler& poseHandler) const noexcept {
            poseHandler.Forward();
        }
    };

    class BackwardAction final {
      public:
        void operator()(PoseHandler &poseHandler) const noexcept {
            poseHandler.Backward();
        }
    };

    class ReverseTurnLeftAction final {
      public:
        void operator()(PoseHandler &poseHandler) const noexcept {
            if(poseHandler.IsReverse()){
                poseHandler.TurnRight();
            }
        }
    };

    class TurnLeftAction final {
      public:
        void operator()(PoseHandler &poseHandler) const noexcept {
            poseHandler.TurnLeft();
        }
    };

    class ReverseTurnRightAction final {
      public:
        void operator()(PoseHandler &poseHandler) const noexcept {
            if (poseHandler.IsReverse()) {
                poseHandler.TurnLeft();
            }
        }
    };

    class TurnRightAction final {
      public:
        void operator()(PoseHandler &poseHandler) const noexcept {
            poseHandler.TurnRight();
        }
    };

    class BeReverseAction final {
      public:
        void operator()(PoseHandler &poseHandler) const noexcept {
            poseHandler.Reverse();
        }
    };

    class BeFastAction final {
      public:
        void operator()(PoseHandler &poseHandler) const noexcept {
            poseHandler.Fast();
        }
    };

    void ActionGroup::PushAction(const ActionType ActionType) noexcept {
        actions.push_back(ActionType);
    }

    void ActionGroup::DoOperate(PoseHandler &poseHandler) const noexcept {
        static std::vector<std::function<void(PoseHandler & poseHandler)>> actionVec = {
            ForwardAction(),   BackwardAction(),         TurnLeftAction(), ReverseTurnLeftAction(),
            TurnRightAction(), ReverseTurnRightAction(), BeFastAction(),   BeReverseAction(),
        };

        std::for_each(actions.begin(), actions.end(), [&poseHandler](const ActionType actionType) mutable noexcept {
            actionVec[static_cast<uint16_t>(actionType)](poseHandler);
        });
    }
} // namespace adas
