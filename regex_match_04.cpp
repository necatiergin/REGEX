#include <regex>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	regex rgx{ "([-+]?[0-9]*)\\.?([0-9]+)" };

	cout << "number of capture groups: " << rgx.mark_count() << "\n";

	std::ifstream ifs{ "floats.txt" };
	if (!ifs) {
		std::cerr << "floats.txt dosyasi acilamadi\n";
		exit(EXIT_FAILURE);
	}

	string entry;

	while (ifs >> entry) {
		if (regex_match(entry, rgx)) {
			cout << entry << " gecerli bir gercek sayi\n";
		}
		else {
			cout << entry << " gecerli bir gercek sayi degil\n";
		}
	}
}
