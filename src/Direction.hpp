#pragma once

#include "Point.hpp"

namespace adas {
class Direction final{
  public:
    static const Direction& GetDirection(const char heading) noexcept;

  public:
    Direction(const unsigned index, const char heading) noexcept;
    
  public:
    const Point& Forward(void) const noexcept;
    const Point& Backward(void) const noexcept;
    const Direction& LeftOne(void) const noexcept;
    const Direction& RightOne(void) const noexcept;

    const char GetHeading(void) const noexcept; //get heading char

  private:
    unsigned index; //direction 0 1 2 3
    char heading; //direction char E S W N
};
} // namespace adas
