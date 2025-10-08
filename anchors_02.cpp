#include <iostream>
#include <regex>
#include <string>

int main() 
{
    std::string text = "dog\ncat\nbird";
    std::regex pattern(R"(\w+$)");

    std::smatch match;
    if (std::regex_search(text, match, pattern))
        std::cout << match.str() << '\n';
}
