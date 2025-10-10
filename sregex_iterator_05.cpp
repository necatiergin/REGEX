#include <string>
#include <iostream>
#include <regex>
#include <algorithm>
#include <iterator>

int main()
{
    std::string str;
    std::cout << "bir yazi girin: ";
    std::getline(std::cin, str);
    std::regex rgx("\\b[a-z]+(han|nur|can)\\b"); // whitespace

    std::for_each(std::sregex_iterator(str.begin(), str.end(), rgx), std::sregex_iterator{},
        [](const auto& sm) {
            std::cout << sm.str() << " " << sm.str(1) << '\n';
        }
    );
}
