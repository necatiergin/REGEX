#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::string file_to_str(const std::string& fname)
{
	std::ifstream ifs{ fname };
	if (!ifs) {
		std::cerr << "dosya acilamiyor\n";
		throw std::runtime_error{ fname + " cannot be opened!" };
	}
	return std::string (std::istreambuf_iterator<char>{ifs}, {});
}

int main()
{
	using namespace std;

	auto s = file_to_str("tor.txt");

	regex rgx{ R"(\w+tor\w+)" };

	for (sregex_iterator iter{ s.begin(), s.end(), rgx }, end; iter != end; ++iter) {
		cout << iter->str() << " " << iter->position() << '\n';
	}
}
