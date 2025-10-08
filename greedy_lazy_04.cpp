// greedy or lazy 

#include <string>
#include <regex>
#include <iostream>

int main() 
{
	std::string str = "xxxxx";
	std::regex greedy("x{2,4}");
	std::regex lazy("x{2,4}?");
	std::smatch sm;

	std::regex_search(str, sm, greedy);
	std::cout << "greedy: [" << sm.str() << "]\n";

	std::regex_search(str, sm, lazy);
	std::cout << "lazy:   [" << sm.str() << "]\n";
}
