#include "Direction.hpp"

namespace adas{
    //4 directions
    static const Direction directions[4] = {
        {0, 'E'},
        {1, 'S'},
        {2, 'W'},
        {3, 'N'},
    };

    //four positions
    static const Point points[4] = {
        {1, 0},
        {0, -1},
        {-1, 0},
        {0, 1},
    };

    const Direction& Direction::GetDirection(const char heading) noexcept{
        for(const auto& direction : directions) {
            if(direction.heading == heading){
                return direction;
            }
        }
        return directions[3]; //default direction
    }

    Direction::Direction(const unsigned index, const char heading) noexcept : index(index), heading(heading) {
        
    }

    const Point& Direction::Forward() const noexcept {
        return points[index];
    }
    
    const Point& Direction::Backward() const noexcept {
        return points[(index + 2) % 4];
    }

    const Direction& Direction::LeftOne() const noexcept {
        return directions[(index + 3) % 4];
    }

    const Direction& Direction::RightOne() const noexcept {
        return directions[(index + 1) % 4];
    }

    const char Direction::GetHeading() const noexcept{
        return heading;
    }
}