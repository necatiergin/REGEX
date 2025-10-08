// greedy or lazy 

#include <vector>
#include <string>
#include <regex>
#include <iostream>

int main() 
{
	std::string text = "ab";
	std::regex greedy("a?");
	std::regex lazy("a??");
	std::smatch sm;

	std::regex_search(text, sm, greedy);
	std::cout << "greedy: [" << sm.str() << "]\n";

	std::regex_search(text, sm, lazy);
	std::cout << "lazy:   [" << sm.str() << "]\n";
}
