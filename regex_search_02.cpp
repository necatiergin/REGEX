#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <random>

using namespace std;


//(\d{4})\.([a-f]{4})\.(\d{4})

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
	auto svec = file_to_vec("numbers.txt");
	std::cout << "toplam cumle sayisi: " << svec.size() << "\n";

	std::string sreg{ R"((\d{4})\.([A-F]{4})\.(\d{4}))" };

	std::regex rgx{ sreg };

	std::ofstream ofs{ "out.txt" };
	if (!ofs) {
		std::cerr << "out.txt dosyasi olusturulamadi\n";
		exit(EXIT_FAILURE);
	}


	std::smatch sm;

	ofs << "regex string : " << sreg << "\n\n";
	for (const auto& s : svec) {
		if (std::regex_search(s, sm, rgx)) {
			//ofs << sm[0] << " (" << sm[1] << ") (" << sm[2] << ")\n";
			//ofs << sm[0].str() << " (" << sm[1].str() << ") (" << sm[2].str() << ")\n";
			ofs << sm.str(0) << " (" << sm.str(1) << ") (" << sm.str(2) << ")\n";
		}
	}
}
