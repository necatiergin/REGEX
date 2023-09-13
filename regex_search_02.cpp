#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "nutility.h"


//(\d{4})\.([a-f]{4})\.(\d{4})

int main()
{
	auto svec = file_to_strvec("numbers.txt");
	std::cout << "toplam cumle sayisi: " << svec.size() << "\n";

	//burada dilediğiniz regex stringini oluşturun:
	std::string sreg{ R"((\d{4})\.([a-f]{4})\.(\d{4}))" };

	std::regex rgx{ sreg };

	auto ofs = create_text_file("out.txt");

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
