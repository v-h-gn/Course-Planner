#ifndef __ABSTRACTMAJOR_HPP
#define __ABSTRACTMAJOR_HPP

#include "../CatalogReader.hpp"
#include <vector>
#include <string>

class AbstractMajor {
    protected:
        string name;
        vector<string>* requiredCourses;
    public:
        AbstractMajor() {}

        virtual int totalUnits() = 0;

        virtual string getName() = 0;

        virtual string getCollege() = 0;

        virtual vector<string>* getRequiredCourses() { return requiredCourses; };
};

#endif //__ABSTRACTMAJOR_HPP__