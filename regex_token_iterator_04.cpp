#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string text = "A=1,B=2,C=3";
    std::regex re(R"(([A-Z])=(\d))");
    int submatches[] = { -1, 1, 2 };

    std::sregex_token_iterator it(text.begin(), text.end(), re, submatches);
    std::sregex_token_iterator end;

    while (it != end) {
        std::cout << "[" << *it++ << "]";
    }
}
