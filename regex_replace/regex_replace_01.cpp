#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str{ "profesyonel butun programcilar projelerdeki tum yazilimsal problemleri cozebilmeli" };
	regex rgx{ "\\b(pro)([^ ]*)" };

	//auto s = regex_replace(str, rgx, "($1)($2)");
	auto s = regex_replace(str, rgx, "($1)($2)", regex_constants::format_first_only);

	cout <<  s  << "\n";
}
