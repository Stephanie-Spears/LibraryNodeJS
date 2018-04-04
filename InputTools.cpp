//
// Created by Stephanie Spears on 4/3/18.
//

#include "InputTools.h"
#include <iostream>
using namespace std;


/* Reads an integer from the input, clears buffer
in: prompt
return: a legal integer
*/
int readInt(const char prompt[]) {
	int intVal;

	cout << endl << prompt;
	cin >> intVal;

	while (!cin) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "You've entered an illegal integer. Please try again: ";
		cin >> intVal;
	}
	cin.ignore(100, '\n');
	return intVal;
}

/* Reads a double from input, clears buffer
in: prompt
return: a legal double
*/
double readDouble(const char prompt[]) {
	double	doubleVal;

	cout << endl << prompt;
	cin >> doubleVal;

	while (!cin) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "You've entered an illegal floating point value. Please try again: ";
		cin >> doubleVal;
	}
	cin.ignore(100, '\n');
	return doubleVal;
}

/* Reads a char from input and clears buffer
in: prompt
return: a char
*/
char readChar(char prompt[]) {
	char aChar;
	cout << endl << prompt;
	cin >> aChar;
	cin.ignore(100, '\n');
	return aChar;
}


/* Reads a c-string from input of max 49 char, capitalizes first letter, clears buffer
in: prompt
out: inputStr
return: none
*/
void readString(const char prompt[], char inputStr[]) {
	cout << endl << prompt;
	cin.get(inputStr, 50, '\n');
	while (!cin) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl << prompt;
		cin.get(inputStr, 50, '\n');
	}
	if (islower(inputStr[0])) {
		inputStr[0] = static_cast<char>(toupper(inputStr[0]));
	}
	cin.ignore(100, '\n');
}