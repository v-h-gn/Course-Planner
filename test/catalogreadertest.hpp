#ifndef __CATALOGREADERTEST_HPP__
#define __CATALOGREADERTEST_HPP__

#include "../major/AbstractMajor.hpp"
#include "../major/CS.hpp"
#include "../major/CHE.hpp"
#include "../major/BIEN.hpp"
#include "../major/CSBA.hpp"
#include "../major/EE.hpp"
#include "../major/ENVE.hpp"
#include "../major/ME.hpp"
#include "../major/CEN.hpp"
#include "../major/MSE.hpp"
#include "../CatalogReader.hpp"

#include "gtest/gtest.h"

TEST(CatalogReaderTest, testConstructCourseHeirarchyCS) {
    AbstractMajor* major = new ComputerScience();

    CatalogReader reader(major);

    ASSERT_NO_THROW(reader.createCourseHeirarchy());
}

TEST(CatalogReaderTest, testConstructCourseHeirarchyCEN) {
    AbstractMajor* major = new ComputerEngineering();

    CatalogReader reader(major);

    ASSERT_NO_THROW(reader.createCourseHeirarchy());
}

TEST(CatalogReaderTest, testConstructCourseHeirarchyMSE) {
    AbstractMajor* major = new MaterialScience();

    CatalogReader reader(major);

    ASSERT_NO_THROW(reader.createCourseHeirarchy());
}

TEST(CatalogReaderTest, testConstructorCourseHeirarchyBIEN) {
    AbstractMajor* major = new Bioengineering();

    CatalogReader reader(major);

    ASSERT_NO_THROW(reader.createCourseHeirarchy());
}

TEST(CatalogReaderTest, testConstructorCourseHeirarchyCHE) {
    AbstractMajor* major = new ChemicalEngineering();

    CatalogReader reader(major);

    ASSERT_NO_THROW(reader.createCourseHeirarchy());
}

TEST(CatalogReaderTest, testConstructorCourseHeirarchyENVE) {
    AbstractMajor* major = new EnvironmentalEngineering();

    CatalogReader reader(major);

    ASSERT_NO_THROW(reader.createCourseHeirarchy());
}

TEST(CatalogReaderTest, testConstructorCourseHeirarchyEE) {
    AbstractMajor* major = new ElectricalEngineering();

    CatalogReader reader(major);

    ASSERT_NO_THROW(reader.createCourseHeirarchy());
}

TEST(CatalogReaderTest, testConstructorCourseHeirarchyCSBA) {
    AbstractMajor* major = new CSBusinessApplications();

    CatalogReader reader(major);

    ASSERT_NO_THROW(reader.createCourseHeirarchy());
}

TEST(CatalogReaderTest, testConstructorCourseHeirarchyME) {
    AbstractMajor* major = new MechanicalEngineering();

    CatalogReader reader(major);

    ASSERT_NO_THROW(reader.createCourseHeirarchy());
}

#endif
