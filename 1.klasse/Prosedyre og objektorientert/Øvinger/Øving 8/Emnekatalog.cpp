#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include"Emnekatalog.h"
using namespace std;

void CourseCatalog::addCourse(string courseName, string courseCode) {
	catalog[courseCode] = courseName;
}

void CourseCatalog::removeCourse(string courseCode) {
	catalog.erase(courseCode);
}

void CourseCatalog::getCourse(string courseCode) {
	cout << catalog[courseCode] << endl;
	
}

CourseCatalog::CourseCatalog() {
	
	map<string, string> catalog;
}

std::ostream& operator<<(std::ostream& os, const CourseCatalog& catalog) {
	for (auto it = catalog.catalog.begin(); it != catalog.catalog.end(); ++it)
		os << it->first << " " << it->second << endl;

	return os;
}