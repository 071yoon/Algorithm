#include <iostream>
#include <algorithm>
using namespace std;

int waiting[10000] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	long long low = 0, hi = 60000000000;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> waiting[i];
	}
	if (N <= M){
		cout << N << "\n";
		return (0);
	}
	long long ret = -1;
	while(low <= hi){
		long long mid = (low + hi) / 2;
		long long children = M;
		for(int i = 0; i < M; i++)
			children = children + (mid / waiting[i]);
		if (children >= N){
			ret = mid;
			hi = mid - 1;
		}
		else low = mid + 1;
	}
	long long children = M;
	for(int i = 0; i < M; i++) children = children + ((ret - 1) / waiting[i]);
	for(int i = 0; i < M; i++){
		if (!(ret % waiting[i])) children++;
		if (children == N){
			cout << i + 1 << "\n";
			break ;
		}
	}
}