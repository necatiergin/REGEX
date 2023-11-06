//regex replace

#include <string>
#include <iostream>
#include <regex>

int main()
{
	using namespace std;

	string str;
	cout << "bir yazi girin: ";
	getline(cin, str);
	regex rgx{ R"(\b(\w+)\s+\1)" };

	cout << regex_replace(str, rgx, "$1") << "\n";

}
