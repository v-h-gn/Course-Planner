#ifndef __COURSE_HPP__
#define __COURSE_HPP__

#include "CourseComponent.hpp"

#include <string>
#include <vector>
#include <iostream>

class Course : public CourseComponent {

        private:
            
            // Declare an vector to store courses
            vector<int> courseComponents;

            string courseName;
            string courseDescription;
            int courseNumber;

            


        public:

            // Constructor
            Course(string newCourseName, int newCourseNumber, string newCourseDescription) : CourseComponent() {
                courseName = newCourseName;
                courseNumber = newCourseNumber;
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
            int getCourseNumber() {
                return courseNumber;
            }

            // Adds other courses to the list 
            void add(CourseComponent newCourseComponent) {
                courseComponents.add(newCourseComponent);
            }

            // Removes courses from the list
            void remove(CourseComponent newCourseComponent) {
                courseComponents.remove(newCourseComponent);
            }

            // Returns the course stored at a specific index
            CourseComponent getComponent(int componentIndex) {
                return courseComponents.at(componentIndex);
            }

            // Check this function
            void displayCourseInfo() { 
                cout << "Course Name: " << getCourseName() << endl;
                cout << "Course Number: " << getCourseNumber() << endl;
                cout << "Course Description: " << getCourseDescription() << endl;
            }


};

#endif // __COURSE_HPP__