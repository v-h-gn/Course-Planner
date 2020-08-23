#ifndef __CATALOGREADER_HPP__
#define __CATALOGREADER_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>
#include <exception>
#include <filesystem>
#include "CourseComponent.hpp"
#include "Course.hpp"
#include "Prerequisite.hpp"
#include "AbstractMajor.hpp"

using namespace std;

/* Authored by Vahagn Tovmasian
 * 
 * The CatalogReader is intended to parse through the resources text file and construct object forms of the courses from the info in the file
 */

class CatalogReader {
    private:
        AbstractMajor* major;
        const string resourcesPath = "../resources";
        const string resourceExtension = ".txt";

        CourseComponent* constructCourse(ifstream& fin) const {
                string courseName;
                int courseUnits;
                string courseDescriptiveName;
                string courseDescription;

                string prerequisites;
                
                // get course info
                getline(fin, courseName);
                getline(fin, courseDescriptiveName);
                courseUnits = stoi(courseDescriptiveName.substr(courseDescriptiveName.size() - 1));
                getline(fin, prerequisites);
                getline(fin, courseDescription);

                string combinedDescription = (courseDescriptiveName.append("\n").append(courseDescription));

                CourseComponent* course = new Course(courseName, courseUnits, combinedDescription, prerequisites);

                getline(fin, courseName); // extract an extra line so that the next loop starts at the beginning of the data.

                return course;
        }

    public:
        CatalogReader(AbstractMajor* major) : major(major) {}
        
        /**
         * This method returns an unordered map of CourseComponents,
         * where the key is the Course and the value is a vector containing
         * the Course, Co-Requisites, and Direct Pre-requisites.
         */
        unordered_map<string, list<CourseComponent*>>* createCourseHeirarchy() const {
            ifstream fin(resourcesPath + major->getName() + resourceExtension);

            unordered_map<string, CourseComponent*>* courses = new unordered_map<string, CourseComponent*>(20);

            // if file can't be opened, the program will fail, we throw exception
            if(!fin.is_open()) {
                throw exception("Error, resource file for your major could not be found.");
            }
            
            while(fin.good() && !fin.eof()) {
                // put file of classes into map for easy access                
                CourseComponent* course = constructCourse(fin);             
                courses->emplace(course->getCourseName(), course);
            }

            unordered_map<string, list<CourseComponent*>>* heirarchy = new unordered_map<string, list<CourseComponent*>>(20);

            for(auto requiredCourse : *(major->getRequiredCourses())) {
                CourseComponent* course = courses->at(requiredCourse);

                // TODO: get prerequisites & put them in heirarchy map.

                
            }


            return heirarchy;
        }
};


#endif // __CATALOGREADER_HPP__