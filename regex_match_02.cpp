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
	std::string sreg{R"(.*([aei][rt]).*([tlsmc]ion).*)" };

	std::regex rgx{sreg};

	std::ofstream ofs{ "out.txt" };
	if (!ofs) {
		std::cerr << "dosya olusturulamadi\n";
		return 1;
	}

	std::smatch sm;

	ofs << "regex string : " << sreg << "\n\n";
	for (const auto &s : svec) {
		if (std::regex_match(s, sm, rgx)) {
			//ofs << sm[0] << " (" << sm[1] << ") (" << sm[2] << ")\n";
			//ofs << sm[0].str() << " (" << sm[1].str() << ") (" << sm[2].str() << ")\n";
			ofs << sm.str(0) << " (" << sm.str(1) << ") (" << sm.str(2) << ")\n";
		}
			
	}
}
