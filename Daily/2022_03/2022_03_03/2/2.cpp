#include <vector>
#include <iostream>
using namespace std;

bool dp[101][25] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int max_pc, cnt, max_time;
	cin >> max_pc >> cnt >> max_time;
	for(int i = 0; i < cnt; i++){
		int pc, time;
		cin >> pc >> time;
		if (time > max_time){
			continue ;
		}
		dp[pc][time] = 1;
		vector <int> tmp;
		for(int i = 1; i < max_time; i++){
			if (dp[pc][i]) tmp.push_back(i);
		}
		for(int i = 0; i < tmp.size(); i++){
			if (tmp[i] + time <= max_time){
				dp[pc][max_time] = 1;
			}
		}
	}
	for(int i = 1; i <= max_pc; i++){
		dp[i][0] = true;
		cout << i << " ";
		for(int j = max_time; j >= 0; j--){
			if (dp[i][j]){
				cout << j << "\n";
				break ;
			}
		}
	}
}
//10mins 17sec