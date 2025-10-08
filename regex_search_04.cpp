#include <iostream>
#include <regex>

int main() 
{
    const char* ptr= "File name: report_2025.txt";
    std::cmatch match;
    std::regex pattern(R"(\d{4})");

    if (std::regex_search(ptr, match, pattern))
        std::cout << "Year found: " << match.str() << '\n';
}
