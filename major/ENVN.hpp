#ifndef __ENVN_HPP__
#define __ENVN_HPP__

#include "AbstractMajor.hpp"

class EnvironmentalEngineering : public AbstractMajor {
    private:
    public:
        EnvironmentalEngineering() : AbstractMajor() {
            this->name = "envn";
        }
};

#endif // __ENVN_HPP__