#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string scrambleWord(string word);

int main() {
	
	scrambleWord("rambunctious");
	scrambleWord("optimistic");
	scrambleWord("programmer");
	scrambleWord("bountiful");
	scrambleWord("software");
	scrambleWord("quell");
	scrambleWord("unique");
	scrambleWord("irony");
	scrambleWord("value");
	scrambleWord("pique");
	scrambleWord("doubt");
	scrambleWord("heart");

	cout << endl << endl;

	// because you're awesome...
	scrambleWord("Thanks");
	scrambleWord("for");
	scrambleWord("grading");
	scrambleWord("my");
	scrambleWord("work!");

	cout << endl << endl << endl;
	
}




string scrambleWord(string word) {

	for (int i = 1; i < word.size() - 1; i++) {
		
		// handles odd indices without interfering with the last letter
		if ((i % 2 == 1) && (i < word.size() - 2)) {

			// handles the i's
			if (word.at(i) == 'i') {
				continue;
			
			// business as usual
			} else {
				word.insert(i, 1, word.at(i + 1));
				word.erase(i + 2, 1);
			}
			
		}
	}

	// output the word
	cout << "Word: " << word << endl;



	return word;
}
