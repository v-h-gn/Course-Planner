#ifndef __MSE_HPP__
#define __MSE_HPP__

#include "AbstractMajor.hpp"

class MaterialScience : public AbstractMajor {
    private:
    public:
        MaterialScience() : AbstractMajor() {
            this->name = "mse";
        }
};

#endif // __MSE_HPP__