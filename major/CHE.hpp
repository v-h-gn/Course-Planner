#ifndef __CHE_HPP__
#define __CHE_HPP__

#include "AbstractMajor.hpp"

class ChemicalEngineering : public AbstractMajor {
    private:
    public:
        ChemicalEngineering() : AbstractMajor() {
            this->name = "chen";
        }
};

#endif // __CHE_HPP__