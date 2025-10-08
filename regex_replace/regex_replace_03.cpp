#include <string>
#include <regex>
#include <iostream>

int main()
{
	std::string str = "corona virus yayiliyor,\n"
		"olu sayisinin artmasindan\r\n"
		"endise ediliyor.\n"
		"Allah ulkemizi korusun\r\n"
		"Amin!";
	std::regex rgx{ "\\r?\\n" };

	auto line = regex_replace(str, rgx, " ");

	std::cout << "[" << line << "]\n";
}
