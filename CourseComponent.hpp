#ifndef __COURSECOMPONENT_HPP__
#define __COURSECOMPONENT_HPP__

#include <string>

using namespace std;

class CourseComponent {

    public:

        // Constructor
        CourseComponent() { };

        // Adds courses to the list 
        virtual void add(CourseComponent *newCourseComponent) = 0;

        // Removes courses from list
        virtual void remove(CourseComponent *newCourseComponent) = 0;

        // Returns the course stored at a specific index
        // CourseComponent getComponent(int componentIndex);

        // Accessor that returns the course name
        virtual string getCourseName() = 0;

        // Accessor that returns the course number
        // Course catalog does not include CRN
        // virtual int getCourseNumber();

        // Accessor that returns the course description
        virtual string getCourseDescription() = 0;

        virtual void displayCourseInfo() = 0;

};

#endif //__COURSECOMPONENT_HPP__
