#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include "Executor.hpp"

namespace adas
{
    //overload Pose ==，global method to compare if two poses are equal
    bool operator==(const Pose &lhs, const Pose &rhs){
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }

    //following two tests test the static method Executor::NewExecutor
    //test1
    TEST(ExecutorTest, should_return_init_pose_when_without_command){
        //given test condition
        //call Executor static method NewExecutor, returns a unique pointer to Executor, so we don't need to delete
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0,0,'E'})); //initial pose

        //when 

        //then
        const Pose target({0,0,'E'}); //create a target pose with {0, 0, 'E'} 
        
    } 
} // namespace adas
