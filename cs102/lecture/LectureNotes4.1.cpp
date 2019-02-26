//Alexander Peters
//Lecture Notes 4.1
//02/26/19
//Swap Functions

#include <iostream>
using namespace std;
void swap(int& a, int& b);

int main() {
	int x = 2;
	int y = 4;
	cout << "x = " << x << ", y = " << y << '\n';

	swap(x,y);

	cout << "After swap...\n";
	cout << "x= " << x << ", y = " << y << '\n';

	return 0;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


///New Import (cmath)
//-Lookup, it's very useful
