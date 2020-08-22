#ifndef __CATALOGREADER_HPP__
#define __CATALOGREADER_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <exception>
#include <filesystem>
#include "CourseComponent.hpp"


/* Authored by Vahagn Tovmasian
 * 
 * The CatalogReader is intended to parse through the resources text file and construct object forms of the courses from the info in the file
 */

class CatalogReader {
    private:
        AbstractMajor* major;
        const std::string resourcesPath = "../resources";
        const std::string resourceExtension = ".txt";
    public:
        CatalogReader(AbstractMajor* major) : major(major) {}
        
        /**
         * This method returns an unordered map of CourseComponents,
         * where the key is the Course and the value is a vector containing
         * the Course, Co-Requisites, and Direct Pre-requisites.
         */
        std::unordered_map<CourseComponent*, std::vector<CourseComponent*>>* createCourseHeirarchy() const {
            std::ifstream fin(resourcesPath + major->getName() + resourceExtension);

            std::unordered_map<CourseComponent*, std::vector<CourseComponent*>>* courses = new std::unordered_map<CourseComponent*, std::vector<CourseComponent*>>(20);

            // if file can't be opened, the program will fail, we throw exception
            if(!fin.is_open()) {
                throw std::exception("Error, resource file for your major could not be found.");
            }

            while(fin.good()) {
                // get components, construct ptr, add to list
                std::vector<CourseComponent*>* requisites = new std::vector<CourseComponent*>(5);

                // TODO: get first course

                // TODO: get id, construct new course component, push it to vector

                // TODO: with id, get prerequisites & corequisites, & push those to vector

                // TODO: with original course component, push it to hashmap with new vector

            }

            return courses;
        }
};


#endif // __CATALOGREADER_HPP__