#include <iostream>

using namespace std;
int main()
{
	int	A,B;

	cin >> A >> B;
	if (A > 0 && B > 0)
		cout << 1 << endl;
	else if (A < 0 && B > 0)
		cout << 2 << endl;
	else if (A < 0 && B < 0)
		cout << 3 << endl;
	else if (A > 0 && B < 0)
		cout << 4 << endl;
}