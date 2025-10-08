#include <regex>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	regex rgx{ "([-+]?[0-9]*)\\.?([0-9]+)" };

	cout << "number of capture groups: " << rgx.mark_count() << "\n";

	ifstream ifs{ "floats.txt" };
	if (!ifs) {
		std::cerr << "cannot open file: float.txt!\n";
		exit(EXIT_FAILURE);
	}

	string entry;

	while (ifs >> entry) {
		if (regex_match(entry, rgx)) {
			cout << entry << " is a valid floating point number\n";
		}
		else {
			cout << entry << " is not a valid floating point number\n";
		}
	}
}
