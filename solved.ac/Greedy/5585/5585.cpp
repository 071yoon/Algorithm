#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int pay, cnt = 0;
	cin >> pay;
	pay = 1000 - pay;
	cnt += pay / 500;
	pay %= 500;
	cnt += pay / 100;
	pay %= 100;
	cnt += pay / 50;
	pay %= 50;
	cnt += pay / 10;
	pay %= 10;
	cnt += pay / 5;
	pay %= 5;
	cnt += pay;
	cout << cnt << "\n";
}