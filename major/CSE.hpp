#ifndef __CS_HPP__
#define __CS_HPP__

#include "AbstractMajor.hpp"

class ComputerScience : public AbstractMajor {
    private:
    public:
        ComputerScience() : AbstractMajor() {
            this->name = "cs";
        }
};

#endif // __CS_HPP__
