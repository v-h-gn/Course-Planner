#ifndef __BIEN_HPP__
#define __BIEN_HPP__

#include "AbstractMajor.hpp"

class Bioengineering : public AbstractMajor {
    private:
    public:
        Bioengineering() : AbstractMajor() {
            this->name = "bien";
        }
};


#endif // __BIEN_HPP__