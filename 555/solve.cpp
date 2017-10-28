#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Deal {
public:
	Deal(string dealer, string cards_1, string cards_2) 
	: dealer(dealer), cards_1(cards_1), cards_2(cards_2) {};

private:
	string dealer; 
	string cards_1; 
	string cards_2;
	vector<string> cards;

public:
	void sort();
	void print();

};

int main () {
	vector<Deal *> deals;
	
	string input;
	getline(cin, input);
	while (input.compare("#") != 0) {
		// Is a beginning of new object
		if (input.compare("N") == 0 || 
			input.compare("E") == 0 || 
			input.compare("S") == 0 || 
			input.compare("W") == 0) {
			string dealer = input;
			string card_1;
			getline(cin, card_1);
			string card_2;
			getline(cin, card_2);

			Deal * newDeal = new Deal(dealer, card_1, card_2);
			deals.push_back(newDeal);
		}
		getline(cin, input);
	}

	cout << deals.size() << endl;

	return 0;
}
