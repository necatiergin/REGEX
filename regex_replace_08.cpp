#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string s = "C++20 is great!";
    std::regex re(R"(C\+\+\d{2})");

    //std::string out = std::regex_replace(s, re, "[$`]");
    //std::string out = std::regex_replace(s, re, "[$']");
    std::string out = std::regex_replace(s, re, "[$']", std::regex_constants::format_no_copy);
    std::cout << out << '\n';
}
