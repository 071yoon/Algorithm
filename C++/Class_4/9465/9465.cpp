#include <iostream>
#include <algorithm>
using namespace std;

int T, n;
int arr[100001][2];
int dp[100001][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> n;
		for(int total = 0; total < 2; total++){
			for(int width = 0; width < n; width++){
				cin >> arr[width][total];
			}
		}
		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[1][0] = dp[0][1] + arr[1][0];
		dp[1][1] = dp[0][0] + arr[1][1];
		int ret = 0;
		for(int k = 2; k < n; k++){
			dp[k][0] = arr[k][0] + max(dp[k - 1][1], dp[k - 2][1]);
			dp[k][1] = arr[k][1] + max(dp[k - 1][0], dp[k - 2][0]);
		}
		cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";


	}

}