#ifndef __COURSECOMPONENT_HPP__
#define __COURSECOMPONENT_HPP__

#include <string>

class CourseComponent {

    public:

        // Constructor
        CourseComponent() { };

        // Adds courses to the list 
        virtual void add(CourseComponent *newCourseComponent);

        // Removes courses from list
        virtual void remove(CourseComponent *newCourseComponent);

        // Returns the course stored at a specific index
        CourseComponent getComponent(int componentIndex);

        // Accessor that returns the course name
        virtual std::string getCourseName();

        // Accessor that returns the course number
        // Course catalog does not include CRN
        // virtual int getCourseNumber();

        // Accessor that returns the course description
        virtual std::string getCourseDescription();

        virtual void displayCourseInfo();

};

#endif //__COURSECOMPONENT_HPP__
