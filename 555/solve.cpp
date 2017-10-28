#include <iostream>
#include <string>

using namespace std;

class Deal {
public:
	Deal(string dealer, string cards_1, string cards_2) 
	: dealer(dealer), cards_1(cards_1), cards_2(cards_2) {};

private:
	string dealer; 
	string cards_1; 
	string cards_2;
};

int main () {
	string dealer;
	getline(cin, dealer);

	string cards_1;
	getline(cin, cards_1);

	string cards_2;
	getline(cin, cards_2);
}