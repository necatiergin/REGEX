#include <regex>
#include <iostream>

using namespace std;

int main()
{
	string sreg{
		R"((\d{4})\.([a-f]{4})\.(\d{4}))"
	};

	cout << "regex expression: " << sreg << "\n\n";
	regex rgx{ sreg };

	string str{ "alican7642.fdce.9245enes" };
	smatch sm;

	if (regex_search(str, sm, rgx)) {
		cout << "str            : " << str << "\n";
		cout << "sm.size()      : " << sm.size() << "\n";
		cout << "sm.prefix()    : " << sm.prefix() << "\n";
		cout << "sm.suffix()    : " << sm.suffix() << "\n";
		cout << "sm[0]          : " << sm[0] << "\n";
		cout << "sm[1]          : " << sm[1] << "\n";
		cout << "sm[2]          : " << sm[2] << "\n";
		cout << "sm[3]          : " << sm[3] << "\n";
		cout << "sm.str()       : " << sm.str() << "\n";
		cout << "sm.str(1)      : " << sm.str(1) << "\n";
		cout << "sm.str(2)      : " << sm.str(2) << "\n";
		cout << "sm.str(3)      : " << sm.str(3) << "\n";
		cout << "sm.length()    : " << sm.length() << "\n";
		cout << "sm.length(0)   : " << sm.length(0) << "\n";
		cout << "sm.length(1)   : " << sm.length(1) << "\n";
		cout << "sm.length(2)   : " << sm.length(2) << "\n";
		cout << "sm.length(3)   : " << sm.length(3) << "\n";
		cout << "sm.position( ) : " << sm.position() << "\n";
		cout << "sm.position(0) : " << sm.position(0) << "\n";
		cout << "sm.position(1) : " << sm.position(1) << "\n";
		cout << "sm.position(2) : " << sm.position(2) << "\n";
		cout << "sm.position(3) : " << sm.position(3) << "\n";
	}


}
