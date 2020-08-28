#ifndef __COURSE_HPP__
#define __COURSE_HPP__

#include "CourseComponent.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Course : public CourseComponent {

    private:    
        string courseRequisites;
    public:
        // Defualt Constructor
        Course() : CourseComponent() {
            courseName = "CRS 001";
            courseDescription = "A default course";
            courseUnits = 4;
            courseRequisites = "PREQ 001";
        }

        // Constructor
        Course(string newCourseName, int numUnits, string newCourseDescription, string newCourseRequisites) : CourseComponent() {
            courseName = newCourseName;
            courseUnits = numUnits;
            courseDescription = newCourseDescription;
            courseRequisites = newCourseRequisites;
        }

        // Accessor that returns Course Requisites
        string getCourseRequisites() {
            return courseRequisites;
        }

        // Adds other courses to the list 
        void add(CourseComponent *newCourseComponent) {
            components.push_back(newCourseComponent);
        }

        // Removes courses from the list
        void remove(CourseComponent *newCourseComponent) {
            std::remove(components.begin(), components.end(), newCourseComponent);
            for (auto course : components) {
                course->remove(newCourseComponent);
            }
            this->update(newCourseComponent);
        }

        // Returns the course stored at a specific index
        CourseComponent* getComponent(int componentIndex) {
            return components.at(componentIndex);
        }

        virtual void update(Observer* toBeRemoved) override {
            for (auto course : components) {
                course->update(toBeRemoved);
            }
        }

        // Check this function
        void displayCourseInfo() { 
            cout << "Course Name: " << getCourseName() << endl;
            cout << "Number of Units: " << getCourseUnits() << endl;
            cout << "Course Description: " << getCourseDescription() << endl;
        }





};

#endif // __COURSE_HPP__