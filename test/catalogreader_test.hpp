#include "../major/AbstractMajor.hpp"
#include "../major/CS.hpp"
#include "../CatalogReader.hpp"
#include "gtest/gtest.h"

TEST(CatalogReaderTest, testConstructCourseHeirarchyCS) {
    AbstractMajor* major = new ComputerScience();

    CatalogReader reader(major);

    reader.setDebugOn(true);

    reader.createCourseHeirarchy();
}
