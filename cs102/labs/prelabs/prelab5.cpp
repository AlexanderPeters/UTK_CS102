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

	cout << "Enter a seed number: ";
	while(!(cin >> numberSeed)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a different number: ";
	}
	
	srand(numberSeed);

	int i = 0;
	while(i < 25) { 
		randomArray[i] = rand();
		i++;
	}

	int sum = 0;
	for(int j = 0; j < 24; j++) {
		sum += randomArray[j];
	}

	cout << "Sum of array = " << sum << '.';
	return 0;
}

