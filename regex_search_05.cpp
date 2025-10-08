#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string str = "Today is 2025-10-08.";
    std::regex pattern(R"(\d{4}-\d{2}-\d{2})");
    std::match_results<std::string::iterator> match;

    if (std::regex_search(str.begin(), str.end(), match, pattern))
        std::cout << "Date found: " << match.str() << '\n';
}
