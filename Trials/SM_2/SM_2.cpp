#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int p, n, h, x, y;
	cin >> p >> n >> h;
	vector <int> computers[100];
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		computers[x - 1].push_back(y);
	}
	int ret[100] = {0};
	for(int i = 0; i < p; i++){
		int dp[25] = {0};
		dp[0] = 1;
		for(int j = 0; j < computers[i].size(); j++){
			if (computers[i][j] > h)
				continue ;
			else{
				for(int k = 0; k <= h; k++){
					if (dp[k] == 1 && ((k + computers[i][j]) <= h)){
						dp[k + computers[i][j]] = 1;
						ret[i] = max(ret[i], k + computers[i][j]);
					}
				}
			}
		}
	}
	for(int i = 0; i < p; i++){
		cout << i + 1 << " " << ret[i] << "\n";
	}
}