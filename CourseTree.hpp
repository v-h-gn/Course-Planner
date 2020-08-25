#ifndef __COURSETREE_HPP__
#define __COURSETREE_HPP__

#include "CourseComponent.hpp"
#include "AbstractMajor.hpp"
#include <string>
#include <iostream>

using namespace std;

struct CourseNode {

    string courseName;
    int key;
    vector<CourseNode*> children;
    CourseNode()
};






#endif // __COURSETREE_HPP__