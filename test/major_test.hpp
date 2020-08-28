#ifndef __MAJOR_TEST_HPP__
#define __MAJOR_TEST_HPP__

#include "../major/AbstractMajor.hpp"
#include "../major/BIEN.hpp"
#include "../major/CEN.hpp"

TEST(CENTest, getRequirements) {
    AbstractMajor* major = new ComputerEngineering();

    major->getRequirements();
    
    for(auto course : (major->getRequiredCourses())) {
        EXPECT_TRUE(course.length() > 1);
    }
}
#endif