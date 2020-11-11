#include <iostream>
#include <fstream>
#include <string>
#include<map>
using namespace std;

class CourseCatalog {
private:
	map<string, string> catalog;
public:
	CourseCatalog();
	void addCourse(string courseName, string courseCode);
	void removeCourse(string courseCode);
	void getCourse(string courseCode);
	friend std::ostream& operator<<(std::ostream&, const CourseCatalog& catalog);
};

std::ostream& operator<<(std::ostream& os , const CourseCatalog& catalog);