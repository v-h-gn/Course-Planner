#ifndef __COURSE_HPP__
#define __COURSE_HPP__

#include "CourseComponent.hpp"

#include <string>
#include <vector>
#include <iostream>

class Course : public CourseComponent {

        protected:
            
            // Declare an vector to store courses
            vector<CourseComponent*> courses;

            string courseName;
            string courseDescription;
            int courseUnits;
            // int courseNumber;

            


        public:

            // Constructor
            Course(string newCourseName, int numUnits, string newCourseDescription) : CourseComponent() {
                courseName = newCourseName;
                courseUnits = numUnits;
                courseDescription = newCourseDescription;
            }

            // Accessor that returns Course Name
            string getCourseName() {
                return courseName;
            }

            // Accessor that returns Course Description
            string getCourseDescription() {
                return courseDescription;
            }

            // Accessor that returns Course Number
            int getNumUnits() {
                return courseUnits;
            }

            // Adds other courses to the list 
            void add(CourseComponent *newCourseComponent) {
                courseComponents.push_back(newCourseComponent);
            }

            // Removes courses from the list
            void remove(CourseComponent *newCourseComponent) {
                unsigned int i;
                for (i = 0; i < courses.size(); ++i) {
                    if (courses[i] == newCourseComponent) {
                        delete newCourseComponent;
                    }
                }
            }

            // Returns the course stored at a specific index
            CourseComponent getComponent(int componentIndex) {
                return courseComponents.at(componentIndex);
            }

            // Check this function
            void displayCourseInfo() { 
                cout << "Course Name: " << getCourseName() << endl;
                cout << "Number of Units: " << getNumUnits() << endl;
                cout << "Course Description: " << getCourseDescription() << endl;
            }





};

#endif // __COURSE_HPP__