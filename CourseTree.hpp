#ifndef __COURSETREE_HPP__
#define __COURSETREE_HPP__

#include "CourseComponent.hpp"
#include "AbstractMajor.hpp"
#include <string>
#include <iostream>

using namespace std;

struct CourseNode {

    private:

        string courseName;
        vector<CourseNode*> children;

        CourseNode* parent;
        CourseNode* next;

    public:
        // Default constructor
        CourseNode() {
            courseName = "";
            children = 0;
            parent = 0;
            next = 0;
        }

        CourseNode(string courseName) {
            courseName = courseName;
            children = 0;
            parent = 0;
            next = 0;
        }

        void addNode(unordered_map<string, list<CourseComponent*>>* majorCourses) {
            
        }
};






#endif // __COURSETREE_HPP__