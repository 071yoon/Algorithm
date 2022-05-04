#include <algorithm>
#include <iostream>
using namespace std;

long long cost[1000010] = {0};
long long cnt, ret = 0, B, C;

void inputs(){
	cin >> cnt >> B >> C;
	for(int i = 0; i < cnt; i++){
		cin >> cost[i];
	}
}

void solve(){
	if (B * 2 <= B + C){ 
		for(int i = 0; i < cnt; i++){ 
			ret += cost[i] * B; 
		} 
		return ; 
	}
	for(int i = 0; i < cnt; i++){
		long long two, three;
		if (cost[i + 1] > cost[i + 2]){ //2개 -> 3개 -> 1개
			two = min(cost[i], cost[i + 1] - cost[i + 2]);
			ret += two * (B + C);
			cost[i] -= two; cost[i + 1] -= two;

			three = min(cost[i], min(cost[i + 1], cost[i + 2]));
			ret += three * (B + 2 * C);
			cost[i] -= three; cost[i + 1] -= three; cost[i + 2] -= three;

			ret += cost[i] * B;
		}
		else{ //3개 -> 2개 -> 1개
			three = min(cost[i], min(cost[i + 1], cost[i + 2]));
			ret += three * (B + 2 * C);
			cost[i] -= three; cost[i + 1] -= three; cost[i + 2] -= three;

			two = min(cost[i], cost[i + 1]);
			ret += two * (B + C);
			cost[i] -= two; cost[i + 1] -= two;

			ret += cost[i] * B;
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