#ifndef __SCHEDULE_HPP__
#define __SCHEDULE_HPP__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Quarter {

    private:
        int quarter;
        int units;

        // Not sure whether to store the classes as Components or as Node
        vector<CourseComponent*> classes;
        
    public: 
        Quarter() {
            quarter = 0;
            units = 0;
        }

        // List of courses get passed into the quarter. Quarters can be stored in a vector to output the schedule
        Quarter(int quarter, int units) {
            quarter = quarter;
            units = units;
        }

        bool add_class(CourseComponent* newClass) {
            classes.push_back(newClass);
        }
};



#endif // __SCHEDULE_HPP__
