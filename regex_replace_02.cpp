//regex replace

#include <string>
#include <iostream>
#include <regex>

int main()
{
	std::string str;
	std::cout << "bir yazi girin: ";
	std::getline(std::cin, str);
	std::regex rgx{ R"(\b(\w+)\s+\1)" };

	std::cout << regex_replace(str, rgx, "$1") << '\n';
}
