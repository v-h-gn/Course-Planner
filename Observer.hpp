#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

#include <iostream>
#include <vector>

using namespace std;

class Observer {
    public:
        Observer() {}
        virtual void update(Observer* toBeRemoved) = 0;   
};


#endif // __OBSERVER_HPP__

