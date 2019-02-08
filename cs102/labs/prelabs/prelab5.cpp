// Alexander Peters
// Prelab 5
// 02/06/19

#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

int main() {
	int numberSeed = 0;
	int randomArray [25];

	//This doesn't work
	//cout << "Enter a seed number: ";
	//while(!(cin >> numberSeed)) {
	//	cin.clear();
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//	cout << "Enter a different number: ";
	//}//
	
	//But this does?
	int number = 0;

	cout << "Enter a number: ";
	while(!(cin >> number)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a number: ";
	}

	srand(number);

	int i = 0;
	while(i < 24) { 
		randomArray[i] = rand();
		i++;
	}

//	int sum = 0;
//	for(int j = 0; j < 24; j++) {
///		sum += randomArray[j];
//	}
//
//	cout << "Sum of array = " + sum + '.';
	return 0;
}

