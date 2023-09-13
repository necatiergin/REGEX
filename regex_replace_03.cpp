#include <string>
#include <regex>
#include <iostream>

using namespace std;

int main()
{
	string str = "corona virus yayiliyor,\n"
		"olu sayisinin artmasindan\r\n"
		"endise ediliyor.\n"
		"Allah ulkemizi korusun\r\n"
		"Amin!";
	regex rgx{ "\\r?\\n" };

	auto line = regex_replace(str, rgx, " ");

	cout << "[" << line << "]\n";

}
