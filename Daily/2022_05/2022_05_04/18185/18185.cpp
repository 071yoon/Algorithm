#include <algorithm>
#include <iostream>
using namespace std;

int cost[10010] = {0};
int cnt, ret = 0;

void inputs(){
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> cost[i];
	}
}

void solve(){
	for(int i = 0; i < cnt; i++){
		int two, three;
		if (cost[i + 1] > cost[i + 2]){ //2개 -> 3개 -> 1개
			two = min(cost[i], cost[i + 1] - cost[i + 2]);
			ret += two * 5;
			cost[i] -= two; cost[i + 1] -= two;

			three = min(cost[i], min(cost[i + 1], cost[i + 2]));
			ret += three * 7;
			cost[i] -= three; cost[i + 1] -= three; cost[i + 2] -= three;

			ret += cost[i] * 3;
		}
		else{ //3개 -> 2개 -> 1개
			three = min(cost[i], min(cost[i + 1], cost[i + 2]));
			ret += three * 7;
			cost[i] -= three; cost[i + 1] -= three; cost[i + 2] -= three;

			two = min(cost[i], cost[i + 1]);
			ret += two * 5;
			cost[i] -= two; cost[i + 1] -= two;

			ret += cost[i] * 3;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
	cout << ret << "\n";
}