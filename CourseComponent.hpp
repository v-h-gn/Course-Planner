#ifndef __COURSECOMPONENT_HPP__
#define __COURSECOMPONENT_HPP__

#include <string>

class CourseComponent {

    public:

        // Constructor
        CourseComponent() { };

        // Adds courses to the list 
        void add(CourseComponent newCourseComponent);

        // Removes courses from list
        void remove(CourseComponent newCourseComponent);

        // Returns the course stored at a specific index
        CourseComponent getComponent(int componentIndex);

        // Accessor that returns the course name
        string getCourseName();

        // Accessor that returns the course number
        int getCourseNumber();

        // Accessor that returns the course description
        string getCourseDescription();

        void displayCourseInfo();




};

#endif //__COURSECOMPONENT_HPP__
