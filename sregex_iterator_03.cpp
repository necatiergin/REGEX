#include <regex>
#include <string>
#include <iostream>

int main() 
{
    const std::string text = "Necati Ergin bugun Ankara'ya uctu. Yarin geri donecek";
    const std::regex  re(R"(\b[A-Z]\w+\b)"); 

        for (std::sregex_iterator it{ text.begin(), text.end(), re }, end; it != end; ++it) {
        const std::smatch& m = *it;               
        std::cout << m.str() << " @pos " << m.position() << '\n';
    }
}
