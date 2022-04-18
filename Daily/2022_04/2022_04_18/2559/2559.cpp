#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
long long maxnum = 0;
int arr[100000] = {0};

void inputs(){
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
}

void solve(){
	long long num = 0;
	for(int i = 0; i < K; i++){
		num += arr[i];
	}
	maxnum = num;
	for(int i = K; i < N; i++){
		num += arr[i];
		num -= arr[i - K];
		maxnum = max(maxnum, num);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
	cout << maxnum << "\n";
}