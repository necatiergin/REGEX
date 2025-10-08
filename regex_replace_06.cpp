#include <string>
#include <regex>
#include <iostream>

int main()
{
    std::string s = "foo bar foo bar foo";
    std::regex re(R"(\bfoo\b)");

    std::cout << 
        regex_replace(s, re, "bom", std::regex_constants::format_first_only);
}
