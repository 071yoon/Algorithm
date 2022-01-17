#include <iostream>
using namespace std;

int arr[100000];
long long dp[100000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num_cnt, cnt;
	cin >> num_cnt >> cnt;
	for(int i = 0; i < num_cnt; i++){
		cin >> arr[i];
		if (i == 0)
			dp[0] = arr[0];
		else
			dp[i] = arr[i] + dp[i - 1];
	}
	int num1, num2;
	while(cnt--){
		cin >> num1 >> num2;
		if (num1 >= 2)
			cout << dp[num2 - 1] - dp[num1 - 2] << "\n";
		else
			cout << dp[num2 - 1] << "\n";
	}
}