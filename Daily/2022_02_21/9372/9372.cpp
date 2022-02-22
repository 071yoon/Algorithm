#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--){
		int ret1, ret2;
		cin >> ret1 >> ret2;
		int tmp1, tmp2;
		while(ret2--){
			cin >> tmp1 >> tmp2;
		}
		cout << ret1 - 1 << "\n";
	}
}
//6 mins 16