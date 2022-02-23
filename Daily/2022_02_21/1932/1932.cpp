#include <iostream>
#include <algorithm>
using namespace std;

int tri[510][510] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < i + 1; j++){
			cin >> tri[i][j];
		}
	}
	int max_val = tri[0][0];
	for(int i = 1; i < cnt; i++){
		tri[i][0] = tri[i][0] + tri[i - 1][0];
		for(int j = 1; j < i + 1; j++){
			tri[i][j] = tri[i][j] + max(tri[i - 1][j], tri[i - 1][j - 1]);
		}
		for(int j = 0; j < i + 1; j++){
			max_val = max(max_val, tri[i][j]);
		}
	}
	cout << max_val << "\n";
}
/*
10 15
18 16 15
20 25 20 19
24 30 27 26 24
*/