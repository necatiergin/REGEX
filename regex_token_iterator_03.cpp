#include <iostream>
#include <regex>
#include <string>

// Split function using regex_token_iterator
std::vector<std::string> split(const std::string& input, const std::string& delim_pattern)
{
    std::regex rgx(delim_pattern);
    std::sregex_token_iterator first{ input.begin(), input.end(), rgx, -1 };
    std::sregex_token_iterator last;
    return { first, last };
}

int main()
{
    std::string text = "apple,orange,,banana,kiwi,pear,melon,,cherry";
    auto tokens = split(text, ",");

    std::cout << "Tokens:\n";
    for (auto& t : tokens)
        if (!t.empty())
            std::cout << "[" << t << "]\n";
}
