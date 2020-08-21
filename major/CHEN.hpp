#ifndef __CHEN_HPP__
#define __CHEN_HPP__

#include "AbstractMajor.hpp"

class ChemicalEngineering : public AbstractMajor {
    private:
    public:
        ChemicalEngineering() : AbstractMajor() {
            this->name = "chen";
        }
};

#endif // __CHEN_HPP__