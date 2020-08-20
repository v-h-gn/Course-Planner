#ifndef __ABSTRACTMAJOR_HPP
#define __ABSTRACTMAJOR_HPP

#include <vector>
#include <string>

class AbstractMajor {
    protected:
        std::string name;
        std::string college;
        std::vector<std::string> requiredCourses;
    public:
        AbstractMajor() {}

        // methods

        // virtual bool containsCourse(CourseComponent* course) = 0;

        virtual int totalUnits() = 0;

        virtual std::string getName() = 0;

        virtual std::string getCollege() = 0;
};

#endif //__ABSTRACTMAJOR_HPP__