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
	cout << "number of words: " << svec.size() << '\n';

	//use your own regex string here
	const string sreg{ R"(.*([aei][rt]).*([tlsmc]ion).*)" };

	std::ofstream ofs{ "out.txt" };
	if (!ofs) {
		std::cerr << "cannot create file\n";
		return 1;
	}

	const regex rgx{ sreg };
	std::smatch sm;

	ofs << "regex string : " << sreg << "\n\n";
	for (const auto& s : svec) {
		if (std::regex_match(s, sm, rgx)) {
			//ofs << sm[0] << " (" << sm[1] << ") (" << sm[2] << ")\n";
			//ofs << sm[0].str() << " (" << sm[1].str() << ") (" << sm[2].str() << ")\n";
			ofs << sm.str(0) << " (" << sm.str(1) << ") (" << sm.str(2) << ")\n";
		}

	}
}
