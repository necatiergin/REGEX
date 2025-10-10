#include <iostream>
#include <regex>
#include <string>

int main() 
{
    std::string text = "3551922 4778198 721347 0171819 834571";
    std::regex re(R"(\d{7})");

    std::string result = std::regex_replace(text, re, "[0555 $&]", std::regex_constants::format_no_copy);
    std::cout << result << '\n';
}
