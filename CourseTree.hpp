#ifndef __COURSETREE_HPP__
#define __COURSETREE_HPP__

#include "CourseComponent.hpp"
#include "AbstractMajor.hpp"
#include <string>
#include <iostream>
#include <list>

using namespace std;

struct CourseNode {

    private:

        string courseName;
        vector<CourseNode*> children;
        vector<CourseNode*> parents;

    public:
        // Default constructor
        CourseNode() {
            courseName = "";
            children = 0;
            parents = 0;
        }

        CourseNode(string courseName) {
            courseName = courseName;
            children = 0;
            parents = 0;
        }

        string getName() {
            return courseName;
        }

        void buildGraph(unordered_map<string, list<CourseComponent*>>* majorCourses) {
            vector<CourseNode> courses;

            for (auto i : majorCourses) {
                CourseNode* newCourse(i.first);
                courses.push_back(newCourse);
            }

            unsigned int i;

            // Iterate through the vector
            // Find the corresponding course in the map, find prerequisites, and set children

            // First loop through the vector containing CourseNodes*
            for (i = 0; i < courses.size(); ++i) {

                // And loop through the unordered_map
                for (auto j : majorCourses) {

                    // If CourseName in the vector == the course name on the unordered_map
                    if (courses.at(i).getName() == j.first) {
                        
                        // Loop through the list of CourseComponents
                        for (auto x : j.second) {

                            // Re loop through the vector containing Course Nodes to find the children and push it back
                            for (int j = 0; j < courses.size(); ++i) {

                                // If the CourseNode == CourseComponent name, push back as children
                                if (x.getCourseName() == courses.at(j).getName()) {
                                    courses.at(i)->children.push_back(courses.at(j));

                                }

                            }
                        }
                    }
                }
            }

            // At this point, we have a vector containing CourseNodes with corresponding children
            // Need to set parents
            for (int i = 0; i < courses.size(); ++i) {
                
            }



            
        }
};






#endif // __COURSETREE_HPP__
