#ifndef __EE_HPP__
#define __EE_HPP__

#include "AbstractMajor.hpp"

class ElectricalEngineering : public AbstractMajor {
    private:
    public:
        ElectricalEngineering() : AbstractMajor() {
            this->name = "ee";
        }
};

#endif // __EE_HPP__