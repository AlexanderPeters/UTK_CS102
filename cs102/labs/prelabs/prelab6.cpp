// Alexander Peters
// Prelab 6
// 02/13/19
	
#include <iostream>
using namespace std;

int main() {
	int year = 0;
	int month = 0;
	int day = 0;

	cout << "Enter start date:";
	cin >> year >> month >> day;
	
	//Do it this way
	cout << year << '\n';
	//Don't concatenate in cout !!!!!!!!!!!!!!!!!!!!!!!	
	cout << month << '\n'; 
	cout << day << '\n';

	return 0;
}

