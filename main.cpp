#include "CourseComponent.hpp"
#include "CatalogReader.hpp"
#include "Prerequisite.hpp"
#include "Course.hpp"
#include "major/AbstractMajor.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    // Student passes in major
    string major;

    cout << "Enter a major: ";
    cin >> major;
    cout << endl;

    // Convert user string to uppercase for simplicity purposes
    for_each(major.begin(), major.end(), [](char & c) {
        c = ::toupper(c);
    }

    // Major gets passed into Catalog Reader
    if (major == "BIOENGINEERING" || major == "BIEN" ) {
        AbstractMajor* bien = new Bioengineering();
    }

    else if (major == "CHEMICAL ENGINEERING" || major == "CHEME") {
        AbstractMajor* cheme = new ChemicalEngineering();
    }

    else if (major == "COMPUTER ENGINEERING" || major == "CHEME") {
        AbstractMajor* cen = new ComputerEngineering();
    }

    else if (major == "COMPUTER SCINECE" || major == "COMP SCI") {
        AbstractMajor* cs = new ComputerScience();
    }

    else if (major == "COMPUTER SCIENCE WITH BUSINESS APPLICATIONS" || major == "CSBA") {
        AbstractMajor* csba = new CSBusinessApplications();
    }

    else if (major == "ELECTRICAL ENGINEERING" || major == "EE") {
        AbstractMajor* ee = new ElectricalEngineering();
    }

    else if (major == "ENVIRONMENTAL ENGINEERING" || major == "ENVE") {
        AbstractMajor* enve = new EnvironmentalEngineering();
    }
    
    else if (major == "MECHANICAL ENGINEERING" || major == "ME") {
        AbstractMajor* me = new MechanicalEngineering();
    }

    else if (major == "MATERIALS SCIENCE AND ENGINEERING" || major == "MSE" || major == "MATERIAL SCIENCE AND ENGINEERING") {
        AbstractMajor* mse = new MaterialScience();
    }

    


    








}

