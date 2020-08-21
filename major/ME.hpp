#ifndef __ME_HPP__
#define __ME_HPP__

#include "AbstractMajor.hpp"

class MechanicalEngineering : public AbstractMajor {
    private:
    public:
        MechanicalEngineering() : AbstractMajor() {
            this->name = "me";
        }
};

#endif // __ME_HPP__