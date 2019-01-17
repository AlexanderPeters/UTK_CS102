// Alexander Peters
// Lab 2
// 01/16/19

using namespace std;

// Patch known issue with MinGW
// https://stackoverflow.com/questions/12975341/to-string-is-not-a-member-of-std-says-g-mingw
// Replaces "std" with "patch" in std::to_string
#include <string>
#include <sstream>

namespace patch {
	template < typename T > std::string to_string(const T& n) {
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}
// End Patch

// Main Program
#include <iostream>

int main() {
	string firstName, middleName, streetName, type;
	int age, streetNumber;

	// Read in data
	cout << "Enter your first and middle names: ";
	cin  >> firstName >> middleName;

	cout << "Enter your age: ";
	cin  >> age;

	cout << "Enter you street number, name, and type: ";
	cin  >> streetNumber >> streetName >> type;
	cout << "\n";
	
	// Apply given logic
	string newName = streetName + " " + middleName;
	string newAge = patch::to_string((streetNumber % age) * 3);
	string newNumericAddress = patch::to_string(age * 700 / streetNumber);
	string newStreetName = firstName;

	cout << "You're movie star name is " << newName + ".\n";
	cout << "You will play a " + newAge + " year old. \n";
	cout << "Your address is "+ newNumericAddress + " " + firstName + " " + type + ".\n";
	
	// Terminate
	return 0;
}
// End Main Program
