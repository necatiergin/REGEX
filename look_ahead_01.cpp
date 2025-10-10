#include <iostream>
#include <regex>
#include <string>

int main() 
{
    std::regex re(R"([a-z]oo(?=bar|baz|bom))");
    std::string s = "foobar noobut goobaz loobat moobom";
    for (std::sregex_iterator it(s.begin(), s.end(), re), end; it != end; ++it)
    std::cout << it->str() << '\n';
}
