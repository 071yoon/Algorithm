#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	if (N <= K){
		cout << "0\n";
		return (0);
	}
	int ret = 0;
	while (1){
		int cnt = 0;
		int temp = N;
		while (temp){
			if (temp % 2) cnt++;
			temp /= 2;
		}
		if (cnt > K){
			ret++;
			N++;
			continue;
		}
		break;
	}
	cout << ret << "\n";
}
/*

13 2
1101
1 1 1 1 1 1 1 1 1 1 1 1 1
2 2 2 2 2 2 1
4 4 4 1
8 4 1
8 4 1 1 (+1)
8 4 2
8 4 2 1 1(+2)
8 4 2 2
8 4 4
8 8
16
1000000
1024 2048 4096 9192 

*/