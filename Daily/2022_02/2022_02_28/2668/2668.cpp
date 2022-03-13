#include <vector>
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[101] = {0};
int nums[101] = {0};
vector <int> ret;

void dfs(int start, int now){
	if (!visited[now]){
		visited[now] = 1;
		dfs(start, nums[now]);
	}
	else if (start == now){
		ret.push_back(now);
		return ;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cnt, num;
	cin >> cnt;
	for(int i = 1; i <= cnt; i++){
		cin >> nums[i];
	}
	for(int i = 1; i <= cnt; i++){
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for(int i = 0; i < ret.size(); i++){
		cout << ret[i] << "\n";
	}
}