#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> get_svec(const std::string &fname)
{
	std::ifstream ifs{ fname };
	if (!ifs) {
		std::cerr << "dosya acilamiyor\n";
		throw std::runtime_error{ fname + " dosyasi acilamadi" };
	}

	std::vector<std::string> svec;
	std::string sline;

	while (std::getline(ifs, sline)) {
		svec.emplace_back(sline);
	}

	return svec;
}


int main()
{
	using namespace std;

	auto svec = get_svec("sentences.txt");
	regex r1{ R"(\b\w+\b)" };
	regex r2{ R"(\B\w+\B)" };

	
	for (const auto &s : svec) {
		cout << s << "\n\n";
		for (sregex_iterator iter{ s.begin(), s.end(), r1 }, end; iter != end; ++iter) {
			cout << iter->str() << " ";
		}
		std::cout << "\n\n";
		for (sregex_iterator iter{ s.begin(), s.end(), r2 }, end; iter != end; ++iter) {
			cout << iter->str() << " ";
		}
		std::cout << "\n\n";
		(void)getchar();
		std::system("cls");
	}
}
