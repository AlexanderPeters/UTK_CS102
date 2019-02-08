// Alexander Peters
// Lab 3
// 01/30/19

#include <iostream>

using namespace std;

int main() {
	double left, right;
	char operation;

	cout << "Enter two numbers: ";
	cin >> left >> right;
	
	cout << "Enter operation: ";
	cin >> operation;

	switch (operation) {
		case '+':
		case '-':
		case '*':
		case '/':
		default: {
			cout << "Unknown Operation";
			return 1;
		}
	}

	return 0;
}

