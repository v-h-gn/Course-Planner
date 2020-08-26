#include "../CatalogReader.hpp"
#include "../major/AbstractMajor.hpp"
#include "../major/BIEN.hpp"
#include "../CourseComponent.hpp"

#include <unordered_map>
#include <list>
#include <string>

int main() {
    AbstractMajor* major = new Bioengineering();

    CatalogReader reader(major);

    reader.createCourseHeirarchy();
}