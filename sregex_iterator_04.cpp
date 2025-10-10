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
	return std::string(std::istreambuf_iterator<char>{ifs}, {});
}

int main()
{
	auto s = file_to_str("tor.txt");

	std::regex rgx{ R"(\w+tor\w+)" };

	for (std::sregex_iterator iter{ s.begin(), s.end(), rgx }, end; iter != end; ++iter) {
		std::cout << iter->str() << " " << iter->position() << '\n';
	}
}
