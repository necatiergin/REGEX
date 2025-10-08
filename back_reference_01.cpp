#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string text = "This is is a test test sentence.";
    std::regex pattern(R"(\b(\w+)\s+\1\b)");
   
     std::smatch match;
    while (std::regex_search(text, match, pattern)) {
        std::cout << "Repeated word: " << match[0] << '\n';
        text = match.suffix();
    }
}
