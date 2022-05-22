#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Pointer string: " << *stringPTR << std::endl;
	std::cout << "Reference string: " << stringREF << std::endl;
}