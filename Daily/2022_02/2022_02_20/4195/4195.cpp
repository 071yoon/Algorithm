#include <iostream>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;

unordered_map <string, int> ump;
int parent[200001] = {0};
int adder[200001] = {0};

int cnt;

int finder(int node){
	if (node == parent[node])
		return node;
	else{
		parent[node] = finder(parent[node]);
		return parent[node];
	}
}

void union_(int x, int y){
	x = finder(x);
	y = finder(y);
	if (x != y){
		if (x < y){
			parent[y] = x;
			adder[x] += adder[y];
		}
		else{
			parent[x] = y;
			adder[y] += adder[x];
		}
	}
}

void solve(){
	string name1, name2;
	int index = 1;
	for(int i = 0; i < cnt; i++){
		cin >> name1 >> name2;
		if (ump[name1] == 0)
			ump[name1] = index++;
		if (ump[name2] == 0)
			ump[name2] = index++;
		int x = ump[name1]; int y = ump[name2];
		union_(x, y);
		cout << max(adder[finder(x)], adder[finder(y)]) << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while(tc--){
		ump.clear();
		cin >> cnt;
		for(int i = 1; i <= cnt * 2; i++){
			adder[i] = 1;
			parent[i] = i;
		}
		solve();
	}
}
//27mins 13sec