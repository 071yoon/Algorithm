#include <iostream>

using namespace std;
int main(){
	int	A, ret;

	ret = 0;
	cin >> A;
	for (int i = 1; i < (A + 1); i++)
		ret += i;
	cout << ret << endl;
}