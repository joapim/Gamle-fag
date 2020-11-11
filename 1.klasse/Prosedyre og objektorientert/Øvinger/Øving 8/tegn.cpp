#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include<sstream>
using namespace std;

void statsToFile2() {
	ifstream sheet;
	sheet.open("sheet.txt");
	if (sheet.fail()) {
		cout << "Error loading file" << endl;
		exit(1);
	}

	int words = 0; //Antall ord	
	map<string, int> antall; //Antall ganger hvert ord forekommer
	char my_char;
	int longestWord = 0;
	string lengsteOrd;
	string word;
	string line;
	int lenght = 0;
	int lines = 0; //Antall linjer 
	word.clear();



	while (!sheet.eof()) {
		sheet.get(my_char);
		while (my_char != ' ') {
			word += my_char;
			sheet.get(my_char);
		}
		words += 1;
		if (word != "") {
			antall[word] += 1;
		}
		lenght = word.length();
		if (lenght > longestWord) {
			longestWord = lenght;
			lengsteOrd = word;
		}
		word.clear();
	}

	sheet.close();
	sheet.open("sheet.txt");
	while (!sheet.eof()) {
		getline(sheet, line);
		lines += 1;
	}

	stringstream ss(line);
	string ord; 
	ss >> ord;
	cout << ss << endl;

	sheet.close();

	/*for (auto it = antall.begin(); it != antall.end(); ++it)
		cout << it->first << ":" << it->second << endl;

	cout << endl;

	cout << "Lengste ord: " << lengsteOrd << endl;
	cout << "Antall ord: " << words - 1 << endl;
	cout << "Linjer: " << lines << endl;*/

	
}

