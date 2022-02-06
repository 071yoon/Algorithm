#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int len, min_diff, max_diff;
long long sum = 0;
int original[51][51] = {0};
int district[51][51] = {0};
int direction[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
vector <pair<int, int> > vecs;

void try_open(int x, int y, int index){
	sum += original[x][y];
	vecs.push_back(make_pair(x, y));
	district[x][y] = index;
	for(int i = 0; i < 4; i++){
		int new_x = x + direction[i][0];
		int new_y = y + direction[i][1];
		if (new_x >= 0 && new_x < len && new_y >= 0 && new_y < len && district[new_x][new_y] == 0 && 
		(abs(original[x][y] - original[new_x][new_y]) >= min_diff) &&
		(abs(original[x][y] - original[new_x][new_y]) <= max_diff)){
			try_open(new_x, new_y, index);
		}
	}
}

int expandable(int x, int y){
	for(int i = 0; i < 4; i++){
		int new_x = x + direction[i][0];
		int new_y = y + direction[i][1];
		if (new_x >= 0 && new_x < len && new_y >= 0 && new_y < len && district[new_x][new_y] == 0 && 
		abs(original[x][y] - original[new_x][new_y]) >= min_diff &&
		abs(original[x][y] - original[new_x][new_y]) <= max_diff){
			return (1);
		}
	}
	return (0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> len >> min_diff >> max_diff;
	int cnt = 0;
	for(int i = 0; i < len * len; i++)
		cin >> original[i / len][i % len];
	while (1){
		memset(district, 0, sizeof(district));
		for(int i = 1; i <= len * len; i++){
			int x = (i - 1) / len;
			int y = (i - 1) % len;
			if (district[x][y] != 0){
				continue ;
			}
			else{
				if (expandable(x, y)){
					sum = 0;
					try_open(x, y, i);
					sum /= vecs.size();
					int sz = vecs.size();
					for(int i = 0; i < sz; i++){
						original[vecs[i].first][vecs[i].second] = sum;
					}
					vecs.clear();
				}
				else{
					continue ;
				}
			}
		}
		int flag = 1;
		for (int i = 0; i < len * len; i++){
			if (district[i / len][i % len] != 0){
				flag = 0;
				cnt++;
				break;
			}
		}
		if (flag) break ;
	}
	cout << cnt << "\n";
}