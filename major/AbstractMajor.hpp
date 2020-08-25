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

        virtual string getName() { return name; };

        virtual vector<string>* getRequiredCourses() { return requiredCourses; };
};

#endif //__ABSTRACTMAJOR_HPP__