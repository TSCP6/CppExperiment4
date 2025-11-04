#pragma once

namespace adas {

class Point final {
  private:
    int x, y; // position
  public:
    Point(const int x, const int y) noexcept;

    Point(const Point &rhs) noexcept;
    Point &operator=(const Point &rhs) noexcept;

    Point &operator+=(const Point &rhs) noexcept;

  public:
    int GetX(void) const noexcept;
    int GetY(void) const noexcept;
};
} // namespace adas
