#include <regex>
#include <string>
#include <iostream>

int main() 
{
    std::string s{ "234  987 1278 8234" };
    const std::regex re(R"(\d*)"); // çok boş eşleşme üretir
    for (std::sregex_iterator it{ s.begin(), s.end(), re,
                                  std::regex_constants::match_not_null }, end;
        it != end; ++it) {
        std::cout << it->str() << '\n'; 
    }
}
