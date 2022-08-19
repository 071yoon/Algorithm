#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int total, cnt;
	long long total_val = 0;
	cin >> total >> cnt;
	for(int i = 0; i < cnt; i++){
		int price, times;
		cin >> price >> times;
		total_val += price * times;
	}
	if (total_val == total) cout << "Yes\n";
	else cout << "No\n";
}