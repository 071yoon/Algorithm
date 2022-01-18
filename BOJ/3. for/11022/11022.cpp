#include <iostream>

using namespace std;
int main(){
	int	cnt, A, B;

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> A >> B;
		cout << "Case #" << i + 1 << ": " << A << " + " << B << " = " << A + B << "\n";
	}
}