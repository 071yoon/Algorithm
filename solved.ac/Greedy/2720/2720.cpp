#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	cin >> cnt;
	while(cnt--){
		cin >> num;
		cout << num / 25 << " ";
		num %= 25;
		cout << num / 10 << " ";
		num %= 10;
		cout << num / 5 << " ";
		num %= 5;
		cout << num << "\n";
	}
}