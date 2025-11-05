#pragma once
#include <string>

namespace adas {
// car's pose
struct Pose {
    int x;
    int y;
    char heading; // N,S,E,W四个方向
};

// car type enum
enum class ExecutorType {
    NORMAL,
    SPORTS_CAR,
    BUS,
};

// car's executor interface
class Executor {
  public:
    // create an Executor object, return a pointer
    // caller should delete *executor when it's not needed
    static Executor *NewExecutor(
      const Pose &pose = {0, 0, 'N'},
      const ExecutorType executorType = ExecutorType::NORMAL) noexcept;

  public:
    Executor(void) = default;
    virtual ~Executor(void) = default;

    // can't copy, like: Executor b; Executor a = b;(Error)
    Executor(const Executor &) = delete;

    // can't assign, like: Executor a, b; a = b;(Error)
    Executor &operator=(const Executor &) = delete;

  public:
    // query the pose of car, pure virtual method(=0)
    // every child class should have this method, returns current pose of car
    virtual Pose Query(void) const noexcept = 0;

    // pure virtual method, execute string command
    virtual void Execute(const std::string &commands) noexcept = 0;
};
} // namespace adas