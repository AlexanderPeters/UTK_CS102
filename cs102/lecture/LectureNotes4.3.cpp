// Alexander Peters
// LectureNotes4.3
// 02/26/19

#include <iostream>
#include <string>
using namespace std;

void Println(string, s);

int main() {
	string my_string;
	string& ref_string = my_string;
	const string& const_string = my_string;

	cout << "Input a string: ";
	getline(cin, ref_string); //my_string

	Println(my_string);

	return 0;
}

void Println(string s) {
	cout << s << '\n';
}
