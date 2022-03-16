#include <iostream>
using namespace std;

long long N, K;
long long players[1000000] = {0};
long long starter, ender;

void inputs(){
	cin >> N >> K;
	starter = 1000000000;
	for(int i = 0; i < N; i++){
		cin >> players[i];
		starter = min(starter, players[i]);
	}
}

void solution(){
	ender = 2000000000;
	int ret = starter;
	while(starter <= ender){
		long long mid = (starter + ender) / 2;
		long long tmp = K;
		for(int i = 0; i < N; i++){
			if (players[i] < mid){
				tmp -= (mid - players[i]);
			}
		}
		if (tmp >= 0){
			ret = mid;
			starter = mid + 1;
		}
		else
			ender = mid - 1;
	}
	cout << ret << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solution();
}