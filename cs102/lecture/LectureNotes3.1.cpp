// Alexander Peters
// Lecture Notes 3.1
// 02/12/19

#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ofstream out("ints.txt");

	if(!out) {
		cerr << "Unable to open file ints.txt. \n";
		return 1;
	}

	// Output 1-100 to ints.txt
	for(unsigned int i = 1; i <= 100; i++) 
		out << i << '\n';
	out.close();

	return 0;
}

