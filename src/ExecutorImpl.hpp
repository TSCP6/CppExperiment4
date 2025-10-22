#pragma once

#include "Executor.hpp"
#include <string>

namespace adas {
// Detail executor implementation
class ExecutorImpl : public Executor { // public child class
  public:
	// constructor
	explicit ExecutorImpl(const Pose &pose) noexcept;
	// only create ExecutorImpl object explicitly
	// Pose p{1,2,'E'}; ExecutorImpl a(p) (correct); ExecutorImpl b = p (Error)

	// destructor
	~ExecutorImpl() noexcept = default;

	// can't copy
	ExecutorImpl(const ExecutorImpl &) = delete;

	// can't assign
	ExecutorImpl &operator=(const ExecutorImpl &) = delete;

  public:
	// query the pose of car, the detail implementation of parent Query method
	Pose Query(void) const noexcept override;

  private:
	// private member: pose of car
	Pose pose;
};
} // namespace adas