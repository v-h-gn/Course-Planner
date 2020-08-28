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
#include "Observer.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;


class PrintAlgorithm {
public:
    PrintAlgorithm() {}

    virtual void print(CourseComponent*) = 0;
};

class DeepPrint : public PrintAlgorithm {
public:
    DeepPrint() : PrintAlgorithm () {}

    void print(CourseComponent* root) {
        Course* test = dynamic_cast<Course*>(root);
        if (test) {
            return;
        } else {
            for (auto course : root->getCourseVector()) {
                cout << course->getCourseName() << " | ";
                print(course);
            }
            cout << endl;
        }
    }
};

class ShallowPrint : public PrintAlgorithm {
public:
    ShallowPrint() : PrintAlgorithm() {}

    void print(CourseComponent* root) {
        for (auto course : root->getCourseVector()) {
            cout << course->getCourseName() << " | ";
        }
        cout << endl;
    }
};

CourseComponent* buildGraph(CourseComponent** root, const vector<CourseComponent*>* cList, const unordered_map<string, vector<CourseComponent*>*>& courses, bool debugOn) {
    if (debugOn) 
        cout << "Building tree from " << (*root)->getCourseName() << endl << "\t";
    if (cList->size() == 1) {
        if (debugOn)
            cout << "\t" << " --> " << cList->at(0)->getCourseName() << " LEVEL 0" << endl;
        return cList->at(0);
    } else {
        for (auto iter = cList->begin() + 1; iter < cList->end(); iter++) {
            CourseComponent* course = *iter;
            if (debugOn)
                cout << "\t" << " --> " << course->getCourseName() << endl << "\t";
            try {
                (*root)->add(buildGraph(&course, courses.at(course->getCourseName()), courses, debugOn));
            } catch (out_of_range& e) {
                if (debugOn)
                    cout << "\t" << " --> UNFOUND " << endl;
                (*root)->add(new Course(course->getCourseName(), course->getCourseUnits(), course->getCourseDescription(), ""));
            }

        }
        return *root;
    }
}

CourseComponent* buildGraph(const unordered_map<string, vector<CourseComponent*>*>& courses, bool debugOn) {
    
    CourseComponent* root = new Course("Course Planner Root", 0, "", "");
    
    for (auto course : courses) {
        vector<CourseComponent*>* cList = course.second;
        if (!cList->empty()) {
            root->add(buildGraph(&cList->at(0), cList, courses, debugOn));
        }
    }

    return root;
}

int main() {

    string major;
    CourseComponent* root;
    unordered_map<string, vector<CourseComponent*>*> majorCourses;
    PrintAlgorithm* printer;

    cout << "Enter a major (ALL UPPERCASE): ";
    cin >> major;
    cout << endl;

    // Convert user string to uppercase for simplicity purposes

    AbstractMajor* userMajor;
    if (major == "BIOENGINEERING" || major == "BIEN") {
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
        userMajor = new EnvironmentalEngineering();
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

    userMajor->getRequirements();
    // Pass in the major to the CatalogReader
    CatalogReader reader(userMajor);

    reader.setDebugOn(false);
    // Returns unordered map of courses, stored by "name of course", <vector of linked courses and itself>
    majorCourses = reader.createCourseHeirarchy();
    cout << "Succesfully retreived heirarchy" << endl;
    root = buildGraph(majorCourses, false);


    cout << "DISPLAYING COURSE TREE " << endl;
    
    printer = new ShallowPrint();
    printer->print(root);

    cout << "Enter taken courses in the format of: 'CHEM 001A'. Enter 'Q' when done." << endl;
    string userInput;
    cin >> userInput;

    while (userInput != "Q") {
        cin >> userInput;
        root->remove(majorCourses.at(userInput)->at(0));
    }
}


