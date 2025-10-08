#include <regex>
#include <iostream>

int main()
{
    std::regex re(R"(cat|dog)");
    std::string s = "my cat and dog cats and dogs";
    for (std::sregex_iterator it(s.begin(), s.end(), re), end; it != end; ++it)
        std::cout << it->str() << " " << it->position() << '\n';
}
