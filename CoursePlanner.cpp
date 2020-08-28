#include "CatalogReader.hpp"
#include "major/AbstractMajor.hpp"
#include "major/CEN.hpp"

int main() {
  AbstractMajor* major = new ComputerEngineering();
  
  major->getRequirements();
  
  CatalogReader reader(major);
  
  reader.setDebugOn(true);
  
  reader.createCourseHeirarchy();
  	
	return 0;
}