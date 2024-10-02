/* 
	FileIOProgram.cpp
	Matthew Bersalona
	CSCI 123 C
	10/01/2024
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void enterName();
void loadName();

int main() {
	int option;
	do {
		cout << "Press 1 to enter your name or 2 to load your name: ";
		cin >> option;
		cin.ignore();
	} while (option != 1 && option != 2);

	if (option == 1) {
		enterName();
	}
	else if (option == 2) {
		loadName();
	}

	return 0;
}

void enterName() {
	string name;
	ofstream outputFile; 

	outputFile.open("name.txt");
	
	cout << "Please enter your full name: ";
	getline(cin, name);

	cout << "Entering name to file..." << endl;

	outputFile << name << endl;
	outputFile.close();

	loadName();
}

void loadName() {
	string name;
	ifstream inputFile;

	inputFile.open("name.txt");

	if (inputFile.fail()) {
		cout << "The file doesn't exist yet. " << endl;
		enterName();
	}
	else {
		getline(inputFile, name);
		cout << "Your Name is " << name << ".";
	}

	inputFile.close();
}