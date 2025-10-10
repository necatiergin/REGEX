#include <iostream>
#include <string>
#include <regex>

int main()
{
	using iterator = std::sregex_token_iterator;

	std::string str("projede projeyi basariya ulastiracak profesyonel programcilar gerekiyor");
	std::regex rgx("\\b(pro)([^ ]*)");

	iterator rend;

	std::cout << "all matches:\n";
	for (iterator iter(str.begin(), str.end(), rgx, 0); iter != rend; ++iter)
		std::cout << " [" << *iter << "]";

	std::cout << "\n\n";

	std::cout << "second submatches:";
	for (iterator iter(str.begin(), str.end(), rgx, 2); iter != rend; ++iter)
		std::cout << " [" << *iter << "]";

	std::cout << "\n\n";

	std::cout << "first and second submatches:";
	for (iterator iter(str.begin(), str.end(), rgx, { 1, 2 }); iter != rend; ++iter)
		std::cout << " [" << *iter << "]";

	std::cout << "\n\n";

	std::cout << "separators:";

	for (iterator iter(str.begin(), str.end(), rgx, -1); iter != rend; ++iter)
		std::cout << " [" << *iter << "]";

	std::cout << "\n\n";
}
