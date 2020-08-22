#ifndef __PREREQUISITE_HPP__
#define __PREREQUISITE_HPP__

#include "CourseComponent.hpp"
#include "Course.hpp"

#include <iostream>
#include <string>

using namespace std;

class Prerequisite : public CourseComponent {

        protected:

            string courseName;
            string courseDescription;
            int courseUnits;
            
            // Removing this because CRN isn't listed in the catalog
            // int courseNumber;
        
        public:

            // Constructor
            Prerequisite(string newCourseName, int numUnits, string newCourseDescription) : CourseComponent() {
                courseName = newCourseName;
                courseUnits = numUnits;
                courseDescription = newCourseDescription;
            }

            // Accessor that returns the course name
            string getCourseName() {
                return courseName;
            }

            // Accessor that returns the course number
            int getNumUnits() {
                return courseUnits;
            }

            // Accessor that returns the course description
            string getCourseDescription() {
                return courseDescription;
            }

            void displayCourseInfo() { 
                cout << "Course Name: " << getCourseName() << endl;
                cout << "Number of Units: " << getNumUnits() << endl;
                cout << "Course Description: " << getCourseDescription() << endl;
            }


};

#endif // __PREREQUISITE_HPP__
