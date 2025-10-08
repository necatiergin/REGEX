#include <regex>
#include <string>
#include <iostream>

int main() 
{
    std::string s = "Call me at 555-0151617 or 532-3323232.";
    std::regex re(R"(\b\d{3}-\d{7}\b)"); 

    // Replace all with [PHONE]
    std::string out = regex_replace(s, re, "[PHONE]");
    std::cout << out << '\n';
    // Call me at [PHONE] or [PHONE].
}
