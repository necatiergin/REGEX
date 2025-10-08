#include <iostream>
#include <regex>
#include <string>

int main() 
{
    std::string str = "Necati loves REGEX.";
    std::regex pattern("regex", std::regex_constants::icase);

    if (std::regex_search(str, pattern))
        std::cout << "Found 'regex' (case-insensitive)\n";
}
