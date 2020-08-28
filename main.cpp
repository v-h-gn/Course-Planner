#include "course/CourseComponent.hpp"
#include "CatalogReader.hpp"
#include "course/Course.hpp"
#include "course/Prerequisite.hpp"
#include "major/AbstractMajor.hpp"
#include "major/BIEN.hpp"
#include "major/CEN.hpp"
#include "major/CHE.hpp"
#include "major/ENVE.hpp"
#include "major/CS.hpp"
#include "major/CSBA.hpp"
#include "major/EE.hpp"
#include "major/ME.hpp"
#include "major/MSE.hpp"
#include "Schedule.hpp"
#include "Subject.hpp"
#include "Observer.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

void buildGraph(unordered_map<string, vector<CourseComponent*>> courses, AbstractMajor* major, CourseComponent* root) {
	 for(auto course : major->getRequiredCourses()) {
      vector<CourseComponent*> cList;
      try {
		 	 cList = courses.at(course);
		 } catch (out_of_range &e) {
			 
		 }
		 if(cList.size() == 1) {
			  root->add(cList.at(0));
		 } else {
			 for(auto iter = cList.begin() + 1; iter < cList.end(); ++iter) {
			 	    root->add(*iter);
            buildGraph(courses, major, *iter); 
			 }
		 }
	 }
}

int main() {

    // Student passes in major
    string major;

    cout << "Enter a major (ALL UPPERCASE): ";
    cin >> major;
    cout << endl;

    // Convert user string to uppercase for simplicity purposes

    AbstractMajor* userMajor; 
    if (major == "BIOENGINEERING" || major == "BIEN" ) {
        userMajor = new Bioengineering();
    }

    else if (major == "CHEMICAL ENGINEERING" || major == "CHE") {
        userMajor = new ChemicalEngineering();
    }

    else if (major == "COMPUTER ENGINEERING" || major == "CEN") {
        userMajor = new ComputerEngineering();
    }

    else if (major == "COMPUTER SCINECE" || major == "CS") {
        userMajor = new ComputerScience();
    }

    else if (major == "COMPUTER SCIENCE WITH BUSINESS APPLICATIONS" || major == "CSBA") {
        userMajor = new CSBusinessApplications();
    }

    else if (major == "ELECTRICAL ENGINEERING" || major == "EE") {
        userMajor = new ElectricalEngineering();
    }

    else if (major == "ENVIRONMENTAL ENGINEERING" || major == "ENVE") {
        userMajor= new EnvironmentalEngineering();
    }
    
    else if (major == "MECHANICAL ENGINEERING" || major == "ME") {
        userMajor = new MechanicalEngineering();
    }

    else if (major == "MATERIALS SCIENCE AND ENGINEERING" || major == "MSE" || major == "MATERIAL SCIENCE AND ENGINEERING") {
        userMajor = new MaterialScience();
    }

    // Program exits if the user inputs an invalid major
    else {
        cout << "Invalid major entered." << endl;
        exit(1);
    }

    // Pass in the major to the CatalogReader
    CatalogReader reader(userMajor);
    
    // Returns unordered map of courses, stored by "name of course", <vector of linked courses and itself>
    unordered_map<string, vector<CourseComponent*>> majorCourses = reader.createCourseHeirarchy();

    // TODO
    // Build the tree using the unordered_map majorCourses
    // buildGraph returns list of linked courses, beginning with the lowest course
    CourseComponent* root;
    buildGraph(majorCourses, userMajor, root);

    // Get the classes the user has taken
    vector<string> takenCourses;
    string userInput;

    cout << "Enter taken courses in the format of: 'CHEM 001A'. Enter 'Q' when done." << endl;



    cout << "DISPLAYING COURSE TREE " << endl;
    
    root->displayCourseInfo();

    cin >> userInput;
    takenCourses.push_back(userInput);

    while (userInput != "Q") {
        cin >> userInput;
        takenCourses.push_back(userInput);
    }

    vector<CourseComponent*> courseList = root->getCourseVector();

}


