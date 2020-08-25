#ifndef __SCHEDULE_HPP__
#define __SCHEDULE_HPP__

#include "CourseTree.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Quarter() {

    private:
        int quarter;
        int units;
        vector<CourseComponent*> classes;

    public: 
        Quarter() {
            quarter = 0;
            units = 0;
            classes = 0;
        }

        // List of courses get passed into the quarter. Quarters can be stored in a vector to output the schedule
        Quarter(int quarter, int units, vector<CourseComponent* classes) {
            quarter = quarter;
            units = units;
            classes = classes;
        }



};



#endif // __SCHEDULE_HPP__