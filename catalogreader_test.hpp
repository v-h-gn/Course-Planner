#include "CatalogReader.hpp"
#include "gtest/gtest.h"
#include <fstream>
#include "major/MSE.hpp"

TEST(CatalogReader, testConstructCourse) {
    AbstractMajor* major = new MaterialScience();
    
    CatalogReader reader(major);

    ifstream fin();
    
}
