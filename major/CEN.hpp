#ifndef __CEN_HPP__
#define __CEN_HPP__

#include "AbstractMajor.hpp"

class ComputerEngineering : public AbstractMajor {
    private:
    public:
        ComputerEngineering() : AbstractMajor() {
            this->name = "cen";
        }
};

#endif // __CEN_HPP__