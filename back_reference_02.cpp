#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string date = "2025-10-10";
    std::regex pattern(R"((\d{4})-(\d{2})-\2)");
    

    if (std::regex_match(date, pattern))
        std::cout << "Same month and day detected.\n";
    else
        std::cout << "Different month and day.\n";
}
