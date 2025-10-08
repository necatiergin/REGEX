// greedy or lazy

#include <string>
#include <regex>
#include <iostream>

int main() 
{
	std::string text = "<b>bold</b><i>italic</i>";
	std::regex pattern("<.*>");
	std::smatch match;
	std::regex_search(text, match, pattern);
	std::cout << match.str() << '\n';
	pattern = "<.*?>";
	std::regex_search(text, match, pattern);
	std::cout << match.str() << '\n';
}
