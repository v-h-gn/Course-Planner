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
		unordered_map<string, vector<CourseComponent*>*> createCourseHeirarchy() const {
			ifstream fin(resourcesPath + resourceExtension);
			unordered_map<string, CourseComponent*> courses;
			unordered_map<string, vector<CourseComponent*>*> heirarchy;
			
			if (debugOn) {
				cout << beginDebugString << endl;
				cout << "Reader resourcepath: " << resourcesPath << endl;
			}
			
			courses = getCoursesFromFile(fin);

			for (auto required : major->getRequiredCourses()) {
				vector<CourseComponent*>* cList = new vector<CourseComponent*>();
				if (debugOn) {
					cout << "Attempting to add " << required << " to heirarchy" << endl;
				}
				CourseComponent* course;
				try { // if course cannot be found initially, just make it a prereq
					course = courses.at(required);
				} catch (out_of_range& e) {
					course = new Prerequisite(required, 4, "");
				}
				// push it to the list

				cList->push_back(course);
				try {
					// attempt to cast it to course to see if it has prerequisites;
					Course* courseCast = dynamic_cast<Course*>(course);
					if (courseCast == nullptr) {
						throw bad_cast(); // throw bad cast to get caught so that it can be a prereq type
					}

					// if it passed, get the prereqs in a vector
					vector<string> prereqs = getPrereqs(courseCast->getCourseRequisites());
					// loop through them and see if we can find them in the courses;
					for (auto name : prereqs) {
						if (debugOn) {
							cout << "Adding " << name << " to prereqs of " << courseCast->getCourseName() << endl;
						}
						CourseComponent* temp;
						try {
							temp = courses.at(name); // check if it exists;
						}
						catch (out_of_range& e) {
							// if it doesnt exist, just say we're unable to retrieve and construct a new one;
							temp = new Course(name, 4, "Unable to Retreive", "Unable to Retreive");
							if (debugOn) {
								cout << temp->getCourseName() << " is being added as a constructed prereq" << endl;
							}
						}
						// push it to the cList;
						cList->push_back(temp);
					}
				} catch (bad_cast& e) {
					if (debugOn) {
						cout << "NOT A COURSE, SIMPLY ADDING AS PREREQUISITE" << endl;
					}
				}
				heirarchy.emplace(required, cList);
			}

			if (debugOn) {
				cout << endDebugString << endl;
			}

			return heirarchy;
		}

		void setDebugOn(bool on) {
			this->debugOn = on;

			cout << "Displaying debug set to " << on << endl;
		}
	private:
		unordered_map<string, CourseComponent*> getCoursesFromFile(ifstream& fin) const {
			unordered_map<string, CourseComponent*> courses;
			if (!fin.is_open()) {
				throw runtime_error("Error, resource file for your major could not be found.");
			}

			while (fin.good() && !fin.eof()) {
				// put file of classes into map for easy access                
				CourseComponent* course = constructCourse(fin);
				courses.emplace(course->getCourseName(), course);
			}

			return courses;
		}

		CourseComponent* constructCourse(ifstream& fin) const {
			string courseName, courseDescription, courseTitle, prerequisites, combined;
			vector<string> prereqList;
			int units;

			getline(fin, courseName);
			getline(fin, courseTitle);
			getline(fin, prerequisites);
			getline(fin, courseDescription);
			
			if (debugOn) {
				cout << "--- FILE TEXT ---" << endl;
				cout << courseName << endl << courseTitle << endl << prerequisites << endl << courseDescription << endl;
				cout << "-----------------" << endl;
			}

			prereqList = getPrereqs(prerequisites);
			units = getCourseUnits(courseTitle);

			combined = courseTitle + "\n" + courseDescription;

			CourseComponent* course;
			if (prereqList.size() == 0) {
				course = new Prerequisite(courseName, units, combined);
			} else {
				course = new Course(courseName, units, combined, prerequisites);
			}

			if (debugOn) {
				cout << "-- COURSE CREATED --" << endl;
				course->displayCourseInfo();
				cout << "--------------------" << endl;
			}

			getline(fin, courseName); // one more time so the it skips the empty space

			return course;
		}

		vector<string> getPrereqs(const string prerequisites) const {
			stringstream str(prerequisites);
			vector<string> prereqsList;
			string temp;

			if (debugOn) {
				cout << "-- SPLITTING PREREQUISITES --" << endl;
			}

			str >> std::ws;

			while (getline(str, temp, ',')) {
				temp = temp.substr(temp.find_first_not_of(" "), temp.find_last_not_of(" ") + 1);
				if (debugOn) {
					cout << temp << "|";
				}
				prereqsList.push_back(temp);
			}

			if (debugOn) {
				cout << "-- DONE SPLITTING --" << endl;
			}

			return prereqsList;
		}

		int getCourseUnits(string& courseTitle) const {
			try {
				return stoi(courseTitle.substr(courseTitle.length() - 2));
			} catch (exception &e) {
				return 4;
			}
		}
};

#endif // __CATALOGREADER_HPP__

