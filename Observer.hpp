#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

#include <iostream>
#include <vector>

#include "CourseComponent.hpp"

using namespace std;

class Observer {
    
    private:
        CourseComponent* course;
        bool taken;

    public:
        Observer(CourseComponent* course, bool isTaken) {
            course = course;
            taken = isTaken;
            model->attach(this);
        }

        void update() {
            bool taken = getComponent()->getBool();
        }

    protected:
        CourseComponent *getComponent() {
            return model;
        }

        bool courseTaken() {
            return taken;
        }

        


}


#endif // __OBSERVER_HPP__

