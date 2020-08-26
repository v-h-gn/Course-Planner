#ifndef __ABSTRACTMAJOR_HPP__
#define __ABSTRACTMAJOR_HPP__

#include <vector>
#include <string>

using std::string;
using std::vector;

class AbstractMajor {
    protected:
        string name;
        vector<string>* requiredCourses;
    public:
        AbstractMajor() { requiredCourses = new vector<string>(); }

        virtual string getName() { return name; };

        virtual vector<string>* getRequiredCourses() { return requiredCourses; };
};

#endif //__ABSTRACTMAJOR_HPP__