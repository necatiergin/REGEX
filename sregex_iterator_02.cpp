#include <string>
#include <iostream>
#include <regex>
#include <algorithm>
#include <iterator>

int main()
{
    using namespace std;

    string str;
    cout << "bir yazi girin: ";
    getline(cin, str);
    std::regex rgx("\\b[a-z]+(han|nur)\\b"); // whitespace

    std::for_each(std::sregex_iterator(str.begin(), str.end(), rgx), std::sregex_iterator{}, 
        [](const auto& sm) {
            cout << sm.str() << "\n";
        }
    );
}
