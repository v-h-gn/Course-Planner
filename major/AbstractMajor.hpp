#ifndef __ABSTRACTMAJOR_HPP
#define __ABSTRACTMAJOR_HPP

#include "../CatalogReader.hpp"
#include <vector>
#include <string>

class AbstractMajor {
    protected:
        std::string name;
        std::vector<std::string> requiredCourses;
    public:
        AbstractMajor() {}

        virtual int totalUnits() = 0;

        virtual std::string getName() = 0;

        virtual std::string getCollege() = 0;
};

#endif //__ABSTRACTMAJOR_HPP__