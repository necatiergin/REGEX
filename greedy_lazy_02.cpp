// greedy or lazy

#include <string>
#include <regex>
#include <iostream>

int main() 
{
	std::string text = "aaaaa";
	std::regex pattern("a+");
	std::smatch match;
	std::regex_search(text, match, pattern);
	std::cout << match.str() << '\n';
	pattern = "a+?";
	std::regex_search(text, match, pattern);
	std::cout << match.str() << '\n';
}
