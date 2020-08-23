#ifndef __ENVE_HPP__
#define __ENVE_HPP__

#include "AbstractMajor.hpp"

class EnvironmentalEngineering : public AbstractMajor {
    private:
    public:
        EnvironmentalEngineering() : AbstractMajor() {
            this->name = "enve";
        }
};

#endif // __ENVE_HPP__