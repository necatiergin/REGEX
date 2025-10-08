#include <iostream>
#include <regex>
#include <string>

int main() 
{
    std::string text = "apple\nbanana\navocado pear";
    std::regex pattern(R"(^a\w+)");

    std::sregex_iterator it(text.begin(), text.end(), pattern);
    std::sregex_iterator end;

    for (; it != end; ++it)
        std::cout << it->str() << '\n';
}
