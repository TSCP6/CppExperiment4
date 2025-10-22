#include "Executor.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <tuple>

namespace adas {
// overload Pose ==，global method to compare if two poses are equal
bool operator==(const Pose &lhs, const Pose &rhs) {
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}

/*----------------------
It's worth mentioning that tests should always be created before child class's creation
----------------------*/

// following two tests test the static method Executor::NewExecutor
// Test1: this test tests when given initial pose, if the query result equals to the initial pose
TEST(ExecutorTest, should_return_init_pose_when_without_command) {
    // TEST(test_suite_name, test_name)
    //  given
    //  call Executor static method NewExecutor, returns a unique pointer to Executor, so we don't need to delete
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // initial pose

    // when

    // then
    const Pose target({0, 0, 'E'}); // create a target pose with {0, 0, 'E'}
    ASSERT_EQ(target, executor->Query());
    // use assert to test if target equals to query result
}

TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command) {
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor()); // no initial pose

    // when

    // then
    const Pose target({0, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_face_is_E){
    //given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    //when
    executor->Execute("M");

    //then
    const Pose target({1, 0, 'E'}); //result of correct implementation
    ASSERT_EQ(target, executor->Query());
}
} // namespace adas
