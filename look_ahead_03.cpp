#include <iostream>
#include <regex>
#include <string>

int main() 
{
    std::string text = "Codes: 123 456abc 789 42x 77";

    // no letter after digit
    std::regex pattern(R"(\b\d+(?![A-Za-z]))");

    for (std::sregex_iterator it(text.begin(), text.end(), pattern), end; it != end; ++it)
        std::cout << "Match: " << it->str() << '\n';
}
