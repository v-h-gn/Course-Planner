#include <iostream>

#include "PDFReader.hpp"
#include "CourseComponent.hpp"
#include "Course.hpp"
#include "Prerequisite.hpp"

using namespace std;

int main(int argc, char** argv) {
    string major;
    string catalogName;
    vector<CourseComponent*> coursesTaken;
    if (argc < 3) {
        throw invalid_argument("Error: you must specify the file of your course catalog as well as your major or college");
    } 

    catalogName = argv[1];
    major = argv[2];
    
    for(int i = 3; i < argc; i++) {
        //TODO: construct new CourseComponent* then push to coursesTaken.
    }    
}