#include <iostream>
#include <regex>
#include <string>

int main() 
{
    std::string files = "main.cpp util.h readme.md Makefile app.cc module.cpp";
    std::regex pattern(R"(\b\w+\.(?=cpp)\w+\b)");

    for (std::sregex_iterator it(files.begin(), files.end(), pattern), end; it != end; ++it)
        std::cout << "Other file: " << it->str() << '\n';
}
