#include <iostream>
#include <string>
#include <regex>

int main()
{
	using namespace std;

	string str("projede projeyi basariya ulastiracak profesyonel programcilar gerekiyor");
	regex rgx("\\b(pro)([^ ]*)");   

	sregex_token_iterator rend;

	cout << "uyanlarin tamami\n";
	for (sregex_token_iterator iter(str.begin(), str.end(), rgx, 0); iter != rend; ++iter) 
		std::cout << " [" << *iter << "]";
	
	cout << "\n\n";

	cout << "2. submatch'ler:";
	for (sregex_token_iterator iter(str.begin(), str.end(), rgx, 2); iter != rend; ++iter)
		std::cout << " [" << *iter << "]";

	cout << "\n\n";

	cout << "1. ve 2. submatch'ler:";
	for (sregex_token_iterator iter(str.begin(), str.end(), rgx, { 1, 2 }); iter != rend; ++iter)
		std::cout << " [" << *iter << "]";

	cout << "\n\n";

	cout << "ayiraclar :";
	
	for (sregex_token_iterator iter(str.begin(), str.end(), rgx, -1); iter != rend; ++iter)
		std::cout << " [" << *iter << "]";

	cout << "\n\n";
}
