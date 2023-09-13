#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> get_svec(const std::string &fname)
{
	std::ifstream ifs{fname };
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
	auto svec = get_svec("words.txt");
	std::cout << "toplam cumle sayisi: " << svec.size() << "\n";

	//burada dilediğiniz regex stringini oluşturun:
	//std::string sreg{R"(^co.*ion$)" };
	//std::string sreg{R"(([aeo]).*\1)" };
	std::string sreg{ R"(.*[nst]ec[aeuo].*)" };

	std::regex rgx{sreg};

	std::ofstream ofs{ "out.txt" };
	if (!ofs) {
		std::cerr << "dosya olusturulamadi\n";
		return 1;
	}

	ofs << "regex string : " << sreg << "\n\n";
	for (const auto &s : svec) {
		if (std::regex_match(s, rgx))
			ofs << s << "\n";
	}
}
