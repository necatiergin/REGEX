#include <iostream>
#include <regex>

int main()
{
    using namespace std;

    regex r1{ "necati" };
    cout << "r1 icin alt ifade sayisi : " << r1.mark_count() << "\n";

    regex r2{ "necati (erg)in" };
    cout << "r2 icin alt ifade sayisi : " << r2.mark_count() << "\n";

    regex r3{ "(necati) (ergin)" };
    cout << "r3 icin alt ifade sayisi : " << r3.mark_count() << "\n";
    
    regex r4{ "(nec(ati)rgin)" };
    cout << "r4 icin alt ifade sayisi : " << r4.mark_count() << "\n";

    regex r5{ "\\(necati\\)" };
    cout << "r5 icin alt ifade sayisi : " << r5.mark_count() << "\n";

    regex r6{ "n(eca)ti", regex_constants::nosubs };
    cout << "r6 icin alt ifade sayisi : " << r6.mark_count() << "\n";

    regex r7{ "n(?:eca)ti"};
    cout << "r7 icin alt ifade sayisi : " << r7.mark_count() << "\n";
}
