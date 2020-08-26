#ifndef __PREREQUISITE_HPP__
#define __PREREQUISITE_HPP__

#include "CourseComponent.hpp"

#include <iostream>
#include <string>

class Prerequisite : public CourseComponent {

        public:
            // Default Constructor
            Prerequisite() : CourseComponent() {
                courseName = "PREQ 001";
                courseDescription = "A default prereq";
                courseUnits = 4;
            }

            // Constructor
            Prerequisite(string newCourseName, int numUnits, string newCourseDescription) : CourseComponent() {
                courseName = newCourseName;
                courseUnits = numUnits;
                courseDescription = newCourseDescription;
            }

            // Empty definition because it doesn't do anything
            void add(CourseComponent* p) {}

            void remove(CourseComponent* p) {}

            void displayCourseInfo() { 
                cout << "Course Name: " << getCourseName() << endl;
                cout << "Number of Units: " << getCourseUnits() << endl;
                cout << "Course Description: " << getCourseDescription() << endl;
            }


};

#endif // __PREREQUISITE_HPP__
