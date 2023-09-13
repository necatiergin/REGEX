#include <regex>
#include <string>
#include <iostream>

int main()
{
    using namespace std;
    string s = "murat, kadir, kemal ve aysenur C++ ogrendiler";
    
    regex rgx{ "[\\s,]+" };
    sregex_token_iterator iter{ s.begin(), s.end(), rgx, -1 };
    sregex_token_iterator end;
    for (; iter != end; ++iter) {
        std::cout << iter->str() << "\n";
    }
}
