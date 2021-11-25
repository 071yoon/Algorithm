#include <iostream>

int main()
{
	long double	A;
	long double	B;

	std::cin >> A;
	std::cin >> B;
	std::cout.precision(12);
	std::cout << (A / B) << std::endl;
}