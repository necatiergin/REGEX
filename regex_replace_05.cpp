#include <regex>
#include <string>
#include <iostream>

int main() 
{
	std::string s = "Today: 07/10/2025, Tomorrow: 08/10/2025";

	std::cout << s << '\n';
	std::regex re(R"(\b(\d{2})/(\d{2})/(\d{4})\b)");
	std::string out = std::regex_replace(s, re, "$3-$2-$1");

	std::cout << out << '\n';
}
