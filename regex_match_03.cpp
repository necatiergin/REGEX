#include <regex>
#include "nutility.h"
#include <iostream>


int main()
{
	using namespace std;
	auto svec = get_dictionary("words.txt");
	regex rgx{ ".*([ckprts]+[aeio]+).*([tcln]ion).*" };

	smatch sm;
	for (auto& word : svec) {
		if (regex_match(word, sm, rgx)) {
			cout << word << "  ";
			word.insert(sm.position(1), 1, '[');
			word.insert(sm.position(1) + sm.length(1) + 1, 1, ']');
			word.insert(word.begin() + sm.position(2) + 2, '[');
			word.insert(word.begin() + sm.position(2) + 3 + sm.length(2), ']');
			cout << word;
			(void)getchar();			
		}
	}
}
