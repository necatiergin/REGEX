#include <regex>
#include <iostream>
#include <string>

int main()
{
	std::string str{ "profesyonel butun programcilar projelerdeki tum yazilimsal problemleri cozebilmeli" };
	std::regex rgx{ "\\b(pro)([^ ]*)" };

	auto s = regex_replace(str, rgx, "($1)($2)");
	//auto s = regex_replace(str, rgx, "($1)($2)", regex_constants::format_first_only);

	std::cout << s << '\n';
}
