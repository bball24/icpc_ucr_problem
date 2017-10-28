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

	vector<string> sort();
	void print();

private:
	int getValue(char val) {
		char key[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

		for (unsigned i = 0; i < 13; ++i) {
			if (val == key[i]) {
				return i;
			}
		}

		return -1;
	}


	vector<string> sort_vect(vector<string> suit) {
		//vector<string> sorted;

		// Bubble sort
		int i, j;
		bool swapped = true;
		for (i = 1; swapped && i < suit.size(); ++i) {
			swapped = false;
			for(j = 0; j < suit.size()-i; ++j) {
				if (getValue(suit.at(j).at(1)) > getValue(suit.at(j+1).at(1))) {
					swapped = true;
					string temp = suit.at(j);
					suit.at(j) = suit.at(j+1);
					suit.at(j+1) = temp;
				}
			}
		}

		return suit;
	}

};

vector<string> Player::sort() {
	vector<string> sorted;

	// First sort by suit
	vector<string> C;
	vector<string> D;
	vector<string> S;
	vector<string> H;

	for (unsigned i = 0; i < cards.size(); ++i) {
		if (cards.at(i).at(0) == 'C') 
			C.push_back(cards.at(i));
		else if (cards.at(i).at(0) == 'D') 
			D.push_back(cards.at(i));
		else if (cards.at(i).at(0) == 'S') 
			S.push_back(cards.at(i));
		else if (cards.at(i).at(0) == 'H') 
			H.push_back(cards.at(i));
	}

	C = sort_vect(C);
	D = sort_vect(D);
	S = sort_vect(S);
	H = sort_vect(H);

	// LOL
	for (unsigned i = 0; i < C.size(); ++i) {
		sorted.push_back(C.at(i));
	}

	for (unsigned i = 0; i < D.size(); ++i) {
		sorted.push_back(D.at(i));
	}

	for (unsigned i = 0; i < S.size(); ++i) {
		sorted.push_back(S.at(i));
	}

	for (unsigned i = 0; i < H.size(); ++i) {
		sorted.push_back(H.at(i));
	}

	return sorted;
}

void Player::print() {
	cards = this->sort();
	cout << name << ":";
	for (unsigned i = 0; i < cards.size(); ++i) {
		cout << " " <<  cards.at(i);
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
	string megastring = cards_1 + cards_2;

	string curr_card = "";
	for (unsigned i = 0; i < megastring.length(); ++i) {
		curr_card += megastring.at(i);

		// Every odd index
		if((int)(i%2) != 0) {
			output.push_back(curr_card);
			curr_card = ""; // Clear
		}
	}

	return output;
}

void Deal::deal() {
	players.push_back(new Player("S"));
	players.push_back(new Player("W"));
	players.push_back(new Player("N"));
	players.push_back(new Player("E"));

	// Find dealer
	unsigned dealer_index;
	for (unsigned i = 0; i < players.size(); ++i) {
		if (players.at(i)->getName().compare(dealer) == 0) {
			dealer_index = i;
		}
	}

	this->cards = this->cardify();

	//Deal
	int curr_player = ((dealer_index+1)%players.size()); // First player
	for (unsigned i = 0; i < cards.size(); ++i) {
		players.at(curr_player)->giveCard(cards.at(i));
		// Next player
		curr_player = ((curr_player+1)%players.size());
	}
}

void Deal::print() {
	for (unsigned i = 0; i < players.size(); ++i) {
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

	for (unsigned i = 0; i < deals.size(); ++i) {
		deals.at(i)->deal();
		deals.at(i)->print();
	}

	return 0;
}
