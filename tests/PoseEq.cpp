#include "PoseEq.hpp"
#include "Executor.hpp"

namespace adas{
    // overload Pose ==，global method to compare if two poses are equal
    bool operator==(const Pose &lhs, const Pose &rhs) {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }
}