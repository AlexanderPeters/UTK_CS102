// Alexander Peters
// Lab 4
// 01/30/19

#include <iostream>
#include <limits>

using namespace std;

int main() {
	string command = "";

	while(command == "") {
		cout << "Enter command: ";
		cin >> command;
		if(command != "car" && command != "truck" && command != "done") {
			cout << "Unknown command. " + '\n';
			command = "";
		}	
	}
	return 0;
}
