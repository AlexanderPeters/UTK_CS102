// Alexander Peters
// Lecture 2.1
// 01/22/19

#include <iostream>
using namespace std;

int main() {
	int intVal;
	double realVal;

	cout << "Input an integer and a real number: ";
	cin >> intVal >> realVal;

	if(intVal == realVal) {
		cout << "Values are the same. \n";
		cout << intVal << " equal to " << realVal << ". \n";
	}
	else {
		cout << "Value are different. \n";
		cout << intVal << " not equal to " << realVal << ". \n";
	}

	return 0;
}
