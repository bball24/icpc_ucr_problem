#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
public:
	Player(string name) : name(name) {};

private:
	string name;
	vector<string> cards;

public:
	string getName() {
		return name;
	}

	void giveCard(string card) {
		cards.push_back(card);
	}
};


class Deal {
public:
	Deal(string dealer, string cards_1, string cards_2) 
	: dealer(dealer), cards_1(cards_1), cards_2(cards_2) {};

private:
	string dealer; 
	string cards_1; 
	string cards_2;
	vector<Player *> players;
	vector<string *> cards;

public:
	void sort();
	void print();	

private:

};


void Deal::sort() {
	players.push_back(new Player("N"));
	players.push_back(new Player("E"));
	players.push_back(new Player("S"));
	players.push_back(new Player("W"));

	// Find dealer
	int dealer_index;
	for (int i = 0; i < players.size(); ++i) {
		if (players.at(i)->getName().compare(dealer) == 0) {
			dealer_index = i;
		}
	}

	int curr_player = ((dealer_index+1)%players.size());
	
	curr_player = ((curr_player+1)%players.size());

}


void Deal::print() {
}


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

	for (int i = 0; i < deals.size(); ++i) {
		deals.at(i)->sort();
	}

	return 0;
}
