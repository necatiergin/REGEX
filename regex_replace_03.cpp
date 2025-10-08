#include <string>
#include <regex>
#include <iostream>

int main()
{
	std::string str = "Ahmet Ersoy,\n"
		"Mustafa Kaya,\r\n"
		"Niyazi Eruslu.\n"
		"Tayfun Cihater,\r\n"
		"Nurullah Gezgin!";
	std::regex rgx{ "\\r?\\n" };

	auto line = regex_replace(str, rgx, " ");

	std::cout << "[" << line << "]\n";
}
