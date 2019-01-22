// Alexander Peters
// Lecture 2.2
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
	if(cubeInput == 'y') 
		val = val*val*val; 
	else if(cubeInput != 'n') {
		cerr << "Invalid input. \n";
		return 1;
	}

	cout << "Value is now " << val << ". \n";

	return 0;
}
