#include <regex>
#include <string>
#include <print>


int main()
{
	using namespace std;

	regex rgx{ "(\\d{3})([a-z]{4})(\\d{3})" };
	string str{ "456neco761" };

	smatch s;

	if (regex_match(str, s, rgx)) {
		print("s[0] : {}\n", s[0].str());
		print("s[1] : {}\n", s[1].str());
		print("s[2] : {}\n", s[2].str());
		print("s[3] : {}\n", s[3].str());
		print("s[0].length() : {}\n", s[0].length());
		print("s[1].length() : {}\n", s[1].length());
		print("s[2].length() : {}\n", s[2].length());
		print("s[3].length() : {}\n", s[3].length());
		print("s.position(0) : {}\n", s.position(0));
		print("s.position(1) : {}\n", s.position(1));
		print("s.position(2) : {}\n", s.position(2));
		print("s.position(3) : {}\n", s.position(3));
	}

	for (int cnt{};  auto sm : s) {
		print("submatch[{}] : {} length = {}\n", cnt++, sm.str(), sm.length());
	}
}
