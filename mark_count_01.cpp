#include <iostream>
#include <regex>

int main()
{
    std::regex r1{ "necati" };
    std::cout << "r1 icin alt ifade sayisi : " << r1.mark_count() << '\n';

    std::regex r2{ "necati (erg)in" };
    std::cout << "r2 icin alt ifade sayisi : " << r2.mark_count() << '\n';

    std::regex r3{ "(necati) (ergin)" };
    std::cout << "r3 icin alt ifade sayisi : " << r3.mark_count() << '\n';

    std::regex r4{ "(nec(ati)rgin)" };
    std::cout << "r4 icin alt ifade sayisi : " << r4.mark_count() << '\n';

    std::regex r5{ "\\(necati\\)" };
    std::cout << "r5 icin alt ifade sayisi : " << r5.mark_count() << '\n';

    std::regex r6{ "n(eca)ti", std::regex_constants::nosubs };
    std::cout << "r6 icin alt ifade sayisi : " << r6.mark_count() << '\n';

    std::regex r7{ "n(?:eca)ti" };
    std::cout << "r7 icin alt ifade sayisi : " << r7.mark_count() << '\n';
}
