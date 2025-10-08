// look ahead

#include <regex>
#include <string>
#include <iostream>

int main() 
{
    std::string str = "Code7 CodeX";
    std::regex re(R"([A-Z]\w*(?=\d))");
    std::smatch sm;
    if (std::regex_search(str, sm, re))
        std::cout << "Match: " << sm.str() << '\n'; // "Code"
}
