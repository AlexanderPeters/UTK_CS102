// Alexander Peters
// Prelab 7
// 02/27/19

#include <iostream>
#include <limits>
using namespace std;

void buildDeck(string faces[13], string suits[4], string (&cards)[52]);

int main() {
	string faces[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
	string suits[4] = {"Hearts", "Diamonds", "Spades", "Clubs"};

	string cards[52] = {""};

	buildDeck(faces, suits, cards);
	
	int index;
	cout << "Enter a card index: ";
	cin >> index;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	if(cin.fail() || index > 51 || index < 0) {
		cerr << "Invalid index! \n";
		return 1;
	}
	
	cout << "That's the " <<  cards[index] << '\n';

	return 0;
}

void buildDeck(string faces[13], string suits[4], string (&cards)[52]) {
	int faces_index = 0;
	int suits_index = 0;

	for(int i = 0; i < 52; ++i) {
		cards[i] = faces[faces_index] + " of " + suits[suits_index] + '\n';
		faces_index += 1;

		if(faces_index == 13) {
			faces_index = 0;
			suits_index += 1;
		}
		if(suits_index == 4) suits_index = 0;
	}
}


