#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num, before, ret;
	before = 1;
	cin >> num;
	for(int i = 0; i < num - 1; i++){
		if (i % 2 == 0)
			before = (before * 2 + 1) % 10007;
		else
			before = (before * 2 - 1) % 10007;
	}
	cout << before << "\n";
}