#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

void writeToFile() {
	ofstream input;
	input.open("input.txt");
	if (input.fail()) {
		cout << "Error opening file" << endl;
		exit(1);
	}
	bool avslutt = false;
	string word;
	while (!avslutt) {
		cout << "Write a word you want to append to file: ";
		cin >> word;
		if (word != "quit") {
			input << word << endl;
		}
		if (word == "quit") {
			avslutt = true;
		}
		
	}
	input.close();
}

void readFromFile() {
	ifstream input;
	ofstream output; 
	input.open("input.txt");
	output.open("output.txt");

	if (input.fail()) {
		cout << "Error opening file" << endl;
		exit(1);
	}
	
	if (output.fail()) {
		cout << "Error opening file" << endl;
		exit(1);

	}
	string line;
	if (input)  // 
	{
		int li = 1;
		while (getline(input, line))  
		{
			cout << line << endl;
			output << li << "\t" << line << endl;
			li += 1;
		}
	}
	input.close();
	output.close();
}