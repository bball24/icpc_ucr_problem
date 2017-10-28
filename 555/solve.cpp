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

	void sort();

	void print();
};

void Player::sort() {

}

void Player::print() {
	cout << name << ": ";
	for (int i = 0; i < cards.size(); ++i) {
		cout << cards.at(i);
	}
	cout << endl;
}

class Deal {
public:
	Deal(string dealer, string cards_1, string cards_2) 
	: dealer(dealer), cards_1(cards_1), cards_2(cards_2) {};

private:
	string dealer; 
	string cards_1; 
	string cards_2;
	vector<Player *> players;
	vector<string> cards;

public:
	void deal();
	void print();	

private:
	vector<string> cardify();
};


vector<string> Deal::cardify() {
	vector<string> output;

	return output;
}

void Deal::deal() {
	players.push_back(new Player("S"));
	players.push_back(new Player("W"));
	players.push_back(new Player("N"));
	players.push_back(new Player("E"));

	// Find dealer
	int dealer_index;
	for (int i = 0; i < players.size(); ++i) {
		if (players.at(i)->getName().compare(dealer) == 0) {
			dealer_index = i;
		}
	}

	int curr_player = ((dealer_index+1)%players.size());
	
	//curr_player = ((curr_player+1)%players.size());

}

void Deal::print() {
	for (int i = 0; i < players.size(); ++i) {
		players.at(i)->sort();
		players.at(i)->print();
	}
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
		deals.at(i)->deal();
		deals.at(i)->print();
	}

	return 0;
}
