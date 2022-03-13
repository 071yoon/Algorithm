#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int sz, cnt, x, y;
	cin >> sz >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> x >> y;
		x--; y--;
		if (x >= sz / 2)
			x = sz - x - 1;
		if (y >= sz / 2)
			y = sz - y - 1;
		if (x < y)
			swap(x, y);
		if (y % 3 == 0) cout << "1\n";
		else if (y % 3 == 1) cout << "2\n";
		else cout << "3\n";
	}
}