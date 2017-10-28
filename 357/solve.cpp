#include <iostream>
#include <string>
#include <vector>

using namespace std;




int main() {
	string input;
	while(cin >> input) {
		if (input.compare("\n") == 0)
			break;
		cout << input << endl;

	}

	return 0;
}
