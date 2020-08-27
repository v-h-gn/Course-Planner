#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

#include <iostream>
#include <vector>

#include "Subject.hpp"

using namespace std;

class Observer {

        Subject *model;
        bool taken;

    public:
        Observer(Subject *mod, bool isTaken) {
            model = mod;
            taken = isTaken;
            model->attach(this);
        }

        void update() {
            bool taken = getSubject()->getBool();
        }

    protected:
        Subject *getSubject() {
            return model;
        }

        bool courseTaken() {
            return taken;
        }

        


}


#endif // __OBSERVER_HPP__

