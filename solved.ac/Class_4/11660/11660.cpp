#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, num;
int dp[1025][1025];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int prev = 0;
	for(int x = 1; x <= N; x++){
		for(int y = 1; y <= N; y++){
			cin >> num;
			dp[x][y] = dp[x - 1][y] + dp[x][y - 1] - dp[x - 1][y - 1] + num;
		}
	}
	int x1, x2, y1, y2;
	for(int i = 0; i < M; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 -1] + dp[x1 - 1][y1 - 1] << "\n";
	}
}