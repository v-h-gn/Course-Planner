#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

#include <iostream>
#include <vector>

#include "course/CourseComponent.hpp"

using namespace std;

class Observer {
    
    private:
        CourseComponent* course;
        bool taken;

    public:
        Observer(CourseComponent* course, bool isTaken) {
            course = course;
            taken = isTaken;
            course->attach(this);
        }

        void update() {
            bool taken = getComponent()->isTaken();
        }

    protected:
        CourseComponent *getComponent() {
            return course;
        }

        bool courseTaken() {
            return taken;
        }

        
};


#endif // __OBSERVER_HPP__

