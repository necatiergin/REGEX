#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <regex>
#include <iterator>

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
	cout << "no of sentences: " << svec.size() << "\n";

	//use your regex string here
	//string sreg{R"(^co.*ion$)" };
	string sreg{R"(([aeo]).*\1)" };
	//string sreg{ R"(.*[nst]ec[aeuo].*)" };

	regex rgx{ sreg };

	ofstream ofs{ "out.txt" };
	if (!ofs) {
		cerr << "cannot create file!\n";
		return 1;
	}

	ofs << "regex string : " << sreg << "\n\n";
	for_each(svec.begin(), svec.end(), [&rgx, &ofs](const string& s) {
		if (regex_match(s, rgx))
			print(ofs, "{}\n", s); });
}
