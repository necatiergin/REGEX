#include <regex>
#include <string>
#include <iostream>

int main()
{
    std::string s = "murat, kadir, kemal ve aysenur C++ ogrendiler";

    std::regex rgx{ "[\\s,]+" };
    std::sregex_token_iterator iter{ s.begin(), s.end(), rgx, -1 };
    std::sregex_token_iterator end;
    for (; iter != end; ++iter) {
        std::cout << iter->str() << '\n';
    }
}
