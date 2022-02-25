#include <iostream>
using namespace std;

bool docking[100001] = {0};
int plane[100001] = {0};
int parent[100001] = {0};

int finder(int x){
	if (parent[x] == x)
		return x;
	else{
		parent[x] = finder(parent[x]);
		return parent[x];
	}
}

void union_find(int x, int y){
	x = finder(x);
	y = finder(y);
	parent[x] = y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int gates, planes;
	cin >> gates >> planes;
	int cnt = 0;
	for(int i = 1; i <= gates; i++){
		parent[i] = i;
	}
	for(int i = 1; i <= planes; i++){
		cin >> plane[i];
	}
	for(int i = 1; i <= planes; i++){
		int now = finder(plane[i]);
		if (now == 0) break;
		union_find(now, now - 1);
		cnt++;
	}
	cout << cnt << "\n";
}