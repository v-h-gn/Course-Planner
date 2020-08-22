#ifndef __CSBA_HPP__
#define __CSBA_HPP__

#include "AbstractMajor.hpp"

class CSBusinessApplications : public AbstractMajor {
    private:
    public:
        CSBusinessApplications() : AbstractMajor() {
            this->name = "csba";
        }
};

#endif // __CSBA_HPP__