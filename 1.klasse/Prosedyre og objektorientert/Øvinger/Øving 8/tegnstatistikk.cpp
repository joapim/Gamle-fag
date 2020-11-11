#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void stats_letter() {
	ifstream stats;
	stats.open("stats.txt");
	if (stats.fail()) {
		cout << "Error loading file" << endl;
		exit(1);
	}
	
	int boks[26] = {};
	char my_char;
	while(!stats.eof()){
		stats.get(my_char);
		char y = tolower(my_char);
		int pos = my_char-97;
		boks[pos] += 1;
	}
	stats.close();
	for (int i = 0; i < 26; i++)
		cout << static_cast<char>(i+97)<< ":" <<boks[i] << endl;
}

void statsToFile() {
	ifstream sheet;
	sheet.open("sheet.txt");
	if (sheet.fail()) {
		cout << "Error loading file" << endl;
		exit(1);
	}
	
	int words = 0; //Antall ord	
	map<string,int> antall; //Antall ganger hvert ord forekommer
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
		while (my_char != '\n') {
			word += my_char;
			sheet.get(my_char);
		}
		words += 1;
		if (word!="") {
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
	sheet.close();

	for (auto it = antall.begin(); it != antall.end(); ++it)
		cout << it->first << ":" << it->second << endl;

	cout << endl;

	cout << "Lengste ord: " << lengsteOrd << endl;
	cout <<"Antall ord: " << words-1 << endl;
	cout << "Linjer: " << lines << endl;

	ofstream tegnstats;
	tegnstats.open("tegnstats.txt");
	if (tegnstats.fail()) {
		cout << "Error opening file" << endl;
	}

	tegnstats << "Lengste ord: " << lengsteOrd << endl;
	tegnstats << "Antall ord: " << words - 1 << endl;
	tegnstats << "Linjer: " << lines << endl;

	for (auto it = antall.begin(); it != antall.end(); ++it)
		tegnstats << it->first << ":" << it->second << endl;

}
