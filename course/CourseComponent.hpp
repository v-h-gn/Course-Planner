#ifndef __COURSECOMPONENT_HPP__
#define __COURSECOMPONENT_HPP__

#include <string>
#include <vector>
#include "../Observer.hpp"

using namespace std;

class CourseComponent : public Observer {
    protected:
        string courseName;
        string courseDescription;
        int courseUnits;
        bool taken = false;

        // Create a vector of CourseComponents to store prerequiites
        vector<CourseComponent*> components;

    public:

        // Constructor
        CourseComponent() : Observer() {}

        // Adds courses to the list 
        virtual void add(CourseComponent *newCourseComponent) = 0;

        // Removes courses from list
        virtual void remove(CourseComponent *newCourseComponent) = 0;

        // Returns the course stored at a specific index
        // CourseComponent getComponent(int componentIndex);

        // Accessor that returns the course name
        virtual string getCourseName() {
            return courseName;
        }

        virtual int getCourseUnits() {
            return courseUnits;
        }

        virtual bool isTaken() {
            return taken;
        }

        virtual vector<CourseComponent*> getCourseVector() {
            return components;
        }

        // Accessor that returns the course description
        virtual string getCourseDescription() {
            return courseDescription;
        }

        virtual void update(Observer* toBeRemoved) override {}

        virtual void displayCourseInfo() = 0;

};

#endif //__COURSECOMPONENT_HPP__
