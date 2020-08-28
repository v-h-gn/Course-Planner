#ifndef __SUBJECT_HPP__
#define __SUBJECT_HPP__

#include <iostream>
#include <vector>
#include "course/CourseComponent.hpp"

using namespace std;

class Observer;

class Subject {
    private:
        vector<CourseComponent*> tree;
    public:
        void attach(CourseComponent* course) {
            tree.push_back(course);
        }
        
        void detach(CourseComponent* course) {
            tree.erase(std::remove(tree.begin(), tree.end(), course), tree.end());
        }

        void notify(CourseComponent* toRemove) {
            for (auto course : tree) {
                course->update(toRemove);
            }
        }
};

#endif // __SUBJECT_HPP__