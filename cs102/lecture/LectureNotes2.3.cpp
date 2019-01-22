// Alexander Peters
// Lecture 2.3
// 01/22/19

#include <iostream>
using namespace std;

int main() {
	double val;
	cout << "Enter a real value: ";
	if(!(cin >> val)) {
		cerr << "Not a real number. \n";
		return 2;
	}

	char cubeInput;
	cout << "Do you want to cube the value? "
		 << "(y)es or (n)o: ";
	cin >> cubeInput;

	// Cube if user said yes
	switch(cubeInput) {
		case 'y':
		case 'Y':
			val = val*val*val;
			break;
		case 'n':
		case 'N':
			break;
		default:
			cerr << "Invalid input. \n";
			return 1;
	}

	cout << "Value is now " << val << ". \n";

	return 0;
}
