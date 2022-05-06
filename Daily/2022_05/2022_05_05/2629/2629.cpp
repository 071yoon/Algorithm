#include <iostream>
using namespace std;

bool dp[40001] = {false};
int chus[31] = {0};
int chu_cnt, T;

void solve(int num){
	for(int j = 1; j <= 40000; j++){
		if (dp[j]){
			cout << j - num << "\n";
			cout << j + num << "\n";
			// if (j - chus[i] > 0) dp[j - chus[i]] = true;
			// if (j + chus[i] <= 40000) dp[j + chus[i]] = true;
		}
	}
	cout << "Exit\n";
}

void inputs(){
	cin >> chu_cnt;
	for(int i = 0; i < chu_cnt; i++){
		cin >> chus[i];
		cout << chus[i] << "\n";
		solve(chus[i]);
		dp[chus[i]] = true;
	}
	int tmp;
	cin >> T;
	while(T--){
		cin >> tmp;
		if (dp[tmp]) cout << "Y ";
		else cout << "N ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
}