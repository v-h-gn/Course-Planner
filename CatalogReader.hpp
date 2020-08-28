#ifndef __CATALOGREADER_HPP__
#define __CATALOGREADER_HPP__

#include "major/AbstractMajor.hpp"
#include "course/CourseComponent.hpp"
#include "course/Prerequisite.hpp"
#include "course/Course.hpp"

#include <unordered_map>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class CatalogReader {
	private:
		AbstractMajor* major;
		string resourcesPath = "resources/courses";
		string resourceExtension = ".txt";
		string beginDebugString = "|-- START --- CATALOGREADER --- DEBUG --|";
		string endDebugString =   "|---------------------------------------|";
		bool debugOn;
	public:
		CatalogReader(AbstractMajor* major) {
			this->major = major;
			this->debugOn = false;
		}
		/**
		* This method returns an unordered map of CourseComponents,
		* where the key is the Course and the value is a vector containing
		* the Course, Co-Requisites, and Direct Pre-requisites.
		*/
		unordered_map<string, vector<CourseComponent*>> createCourseHeirarchy() const {
			ifstream fin(resourcesPath + resourceExtension);

			if (debugOn) {
				cout << beginDebugString << endl;
				cout << "Reader resourcepath: " << resourcesPath + resourceExtension  << endl;
			}

			unordered_map<string, CourseComponent*> courses;

			unordered_map<string, vector<CourseComponent*>> heirarchy;
			
			if (!fin.is_open()) {
				throw runtime_error("Error, resource file for your major could not be found.");
			}

			while (fin.good() && !fin.eof()) {
				// put file of classes into map for easy access                
				CourseComponent* course = constructCourse(fin);
				courses.emplace(course->getCourseName(), course);
			}

			if (debugOn) {
				cout << endDebugString << endl;
			}

			return heirarchy;
		}

		CourseComponent* constructCourse(ifstream& fin) const {
			string courseName, courseDescription, courseTitle, prerequisites, combined;
			vector<string> prereqList;
			int units;

			getline(fin, courseName);
			getline(fin, courseTitle);
			getline(fin, prerequisites);
			getline(fin, courseDescription);
			

			getPrereqs(prerequisites, prereqList);
			units = getCourseUnits(courseTitle);

			combined = courseTitle + "\n" + courseDescription;

			CourseComponent* course;
			if (prereqList.size() == 0) {
				course = new Prerequisite(courseName, units, combined);
			} else {
				course = new Course(courseName, units, combined, prerequisites);
			}

			if (debugOn) {
				cout << "--- FILE TEXT ---" << endl;
				cout << courseName << endl << courseTitle << endl << prerequisites << endl << courseDescription << endl;
				cout << "-----------------" << endl;
				cout << "-- COURSE CREATED --" << endl;
				course->displayCourseInfo();
				cout << "--------------------" << endl;
			}

			getline(fin, courseName); // one more time so the it skips the empty space

			return course;
		}

		void getPrereqs(string& prerequisites, vector<string>& prereqsList) const {
			stringstream str(prerequisites);

			string temp;

			if (debugOn) {
				cout << "-- SPLITTING PREREQUISITES --" << endl;
			}


			while (getline(str, temp, ',')) {
				if (debugOn) {
					cout << temp << " ";
				}
				prereqsList.push_back(temp);
			}

			if (debugOn) {
				cout << "-- DONE SPLITTING --" << endl;
			}
		}

		int getCourseUnits(string& courseTitle) const {
			try {
				return stoi(courseTitle.substr(courseTitle.length() - 2));
			} catch (exception &e) {
				return 4;
			}
		}

		void setDebugOn(bool on) {
			this->debugOn = on;

			cout << "Displaying debug set to " << on << endl;
		}
};

#endif // __CATALOGREADER_HPP__

