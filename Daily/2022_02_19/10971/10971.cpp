#include <iostream>
#include <algorithm>
using namespace std;

int cities[11][11] = {0};
int cnt, num, min_val = 987654321;
bool visited[11] = {0};

void dfs(int city, int cntr, int value){
	for(int i = 1; i <= cnt; i++){
		if (cntr == cnt - 1){
			if (i == 1 && cities[city][i] > 0)
				min_val = min(min_val, value + cities[city][i]);
			return ;
		}
		if (!visited[i] && cities[city][i] > 0){
			visited[i] = 1;
			dfs(i, cntr + 1, value + cities[city][i]);
			visited[i] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> cnt;
	for(int i = 1; i <= cnt; i++){
		for(int j = 1; j <= cnt; j++){
			cin >> num;
			if (num > 0){
				cities[i][j] = num;
			}
		}
	}
	visited[1] = 1;
	dfs(1, 0, 0);
	cout << min_val << "\n";
}
//16mins 31sec