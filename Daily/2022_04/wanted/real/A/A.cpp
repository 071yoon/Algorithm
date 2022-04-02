#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N;
int max_val = 2e9;
int org[11] = {0};
bool visited[11] = {0};
int sale[11][11] = {0};

void inputs(){
	cin >> N;
	int tmp;
	for(int i = 1; i <= N; i++){
		cin >> tmp;
		org[i] = tmp;
	}
	for(int i = 1; i <= N; i++){
		cin >> tmp;
		for(int j = 0; j < tmp; j++){
			int saler, price;
			cin >> saler >> price;
			sale[i][saler] = price;
		}
	}
}

void dfs(int cnt, vector <int> &vec){
	if (cnt == N){
		int tmp = 0;
		int changed[11];
		for(int i = 1; i <= N; i++){
			changed[i] = org[i];
		}
		for(int i = 1; i <= N; i++){
			int now = vec[i - 1];
			for(int j = 1; j <= N; j++){
				changed[j] -= sale[now][j];
				if (changed[j] <= 0) changed[j] = 1;
			}
			tmp += changed[now];
		}
		if (tmp < max_val) max_val = tmp;
		return ;
	}
	for(int i = 1; i <= N; i++){
		if (!visited[i]){
			visited[i] = 1;
			vec.push_back(i);
			dfs(cnt + 1, vec);
			vec.pop_back();
			visited[i] = 0;
		}
	}
}

void solve(){
	vector <int> vec;
	dfs(0, vec);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
	cout << max_val << "\n";
}