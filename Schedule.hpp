#ifndef __SCHEDULE_HPP__
#define __SCHEDULE_HPP__

#include "CourseTree.hpp"
#include "CourseTree.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Quarter() {

    private:
        int quarter;
        int units;

        // Not sure whether to store the classes as Components or as Node
        vector<CourseComponent*> classes;
        vector<CourseNode*< courses;

    public: 
        Quarter() {
            quarter = 0;
            units = 0;
            classes = 0;
        }

        // List of courses get passed into the quarter. Quarters can be stored in a vector to output the schedule
        Quarter(int quarter, int units) {
            quarter = quarter;
            units = units;
            classes = 0;
        }

        bool add_class(CourseNode* newClass) {
            class.push_back(newClass);
        }
};



#endif // __SCHEDULE_HPP__
