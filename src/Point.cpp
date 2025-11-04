#include "Point.hpp"

namespace adas
{
    Point::Point(const int x, const int y) noexcept : x(x), y(y){

    }

    Point::Point(const Point &rhs) noexcept : x(rhs.x), y(rhs.y) {

    }

    Point &Point::operator=(const Point &rhs) noexcept{
        if(this != &rhs){
            x = rhs.x;
            y = rhs.y;
        }        
        return *this;
    }

    Point &Point::operator+=(const Point &rhs) noexcept {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    int Point::GetX() const noexcept {
        return x;
    }

    int Point::GetY() const noexcept {
        return y;
    }
} // namespace adas
