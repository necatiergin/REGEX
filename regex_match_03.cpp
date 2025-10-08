#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

vector<string> file_to_vec(const string& fname)
{
	ifstream ifs{ fname };
	if (!ifs) {
		cerr << "dosya acilamiyor\n";
		throw runtime_error{ fname + " cannot be opened!" };
	}

	return vector<string> {istream_iterator<string>{ifs}, {}};
}

int main()
{
	auto svec = file_to_vec("words.txt");
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
