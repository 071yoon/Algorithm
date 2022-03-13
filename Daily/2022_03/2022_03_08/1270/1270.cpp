#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int total;
	cin >> total;
	while(total--){
		long long cnt, num;
		unordered_map <long long, long long> ump;
		cin >> cnt;
		long long flag = 1;
		for(long long i = 0; i < cnt; i++){
			cin >> num;
			if (flag == 0) continue;
			ump[num]++;
			if (ump[num] > cnt / 2){
				cout << num << "\n";
				flag = 0;
			}
		}
		if (flag) cout << "SYJKGW\n";
	}
}