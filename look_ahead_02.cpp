#include <iostream>
#include <regex>
#include <string>

int main() 
{
    std::string str =
        "Links: http://example.com, https://secure.com, http://test.org";

    // "http" kelimesini ara ama ardından "s" gelmesin
    std::regex pattern(R"(http(?!s))");

    std::sregex_iterator it(str.begin(), str.end(), pattern), end;
    for (; it != end; ++it)
        std::cout << "Match: " << it->str() << "  position: " << it->position() << '\n';
}
