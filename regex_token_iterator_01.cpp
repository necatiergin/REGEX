#include <iostream>
#include <string>
#include <regex>

int main()
{
	using iterator = std::sregex_token_iterator;

	std::string str("projede projeyi basariya ulastiracak profesyonel programcilar gerekiyor");
	std::regex rgx("\\b(pro)([^ ]*)");

	iterator rend;

	std::cout << "uyanlarin tamami\n";
	for (iterator iter(str.begin(), str.end(), rgx, 0); iter != rend; ++iter)
		std::cout << " [" << *iter << "]";

	std::cout << "\n\n";

	std::cout << "2. submatch'ler:";
	for (iterator iter(str.begin(), str.end(), rgx, 2); iter != rend; ++iter)
		std::cout << " [" << *iter << "]";

	std::cout << "\n\n";

	std::cout << "1. ve 2. submatch'ler:";
	for (iterator iter(str.begin(), str.end(), rgx, { 1, 2 }); iter != rend; ++iter)
		std::cout << " [" << *iter << "]";

	std::cout << "\n\n";

	std::cout << "ayiraclar :";

	for (iterator iter(str.begin(), str.end(), rgx, -1); iter != rend; ++iter)
		std::cout << " [" << *iter << "]";

	std::cout << "\n\n";
}
