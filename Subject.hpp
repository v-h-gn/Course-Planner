#ifndef __SUBJECT_HPP__
#define __SUBJECT_HPP__

#include <iostream>
#include <vector>

#include "Observer.hpp"

using namespace std;

class Subject {
    private:
        vector<Observer*> views;
        bool taken;

    public:
        void attach(Observer *obs) {
            views.push_back(obs);
        }

        void setBool(bool isTaken) {
            taken = isTaken;
            notify();
        }

        bool getBool() {
            return taken;
        }

        void notify() {
            for (auto i : views) {
                i->update();
            }
        }

};

#endif // __SUBJECT_HPP__