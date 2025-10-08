#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <regex>
#include <iterator>


std::vector<std::string> file_to_vec(const std::string& fname)
{
	std::ifstream ifs{ fname };
	if (!ifs) {
		std::cerr << "cannot open file\n";
		throw std::runtime_error{ fname + " cannot be opened!" };
	}

	return std::vector<std::string> {std::istream_iterator<std::string>{ifs}, {}};
}

int main()
{
	auto svec = file_to_vec("words.txt");
	std::cout << "no of sentences: " << svec.size() << "\n";

	//use your regex string here
	//std::string sreg{R"(^co.*ion$)" };
	std::string sreg{ R"(([aeo]).*\1)" };
	//string sreg{ R"(.*[nst]ec[aeuo].*)" };

	std::regex rgx{ sreg };

	std::ofstream ofs{ "out.txt" };
	if (!ofs) {
		std::cerr << "cannot create file!\n";
		return 1;
	}

	ofs << "regex string : " << sreg << "\n\n";
	for_each(svec.begin(), svec.end(), [&rgx, &ofs](const std::string& s) {
		if (std::regex_match(s, rgx))
			std::print(ofs, "{}\n", s); });
}
