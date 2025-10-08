#include <iostream>
#include <regex>
#include <string>

int main() 
{
    std::string text = "CPU speed: 3.4 GHz, RAM: 16 GB, Storage: 512GB SSD.";
    std::regex pattern(R"((\d+(\.\d+)?)\s*(GB|GHz|mL|kg))");
    std::smatch match;

    while (std::regex_search(text, match, pattern)) {
        std::cout << "Value : " << match.str(1)
            << "  Unit : " << match.str(3) << '\n';
        text = match.suffix();
    }
}
