#include <iostream>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;

int map[501][501];
int min_height = INT_MAX, max_height = 0;
int N, M, B, now_time;

int solve(int cur_height){
	int Box = B;
	now_time = 0;
	for(int row = 0; row < N; row++){
		for(int col = 0; col < M; col++){
			Box += map[row][col] - cur_height;
			if (map[row][col] > cur_height){
				now_time += 2 * (map[row][col] - cur_height);
			}
			else if (map[row][col] < cur_height){
				now_time += 1 * (cur_height - map[row][col]);
			}
		}
	}
	if (Box >= 0)
		return (1);
	else
		return (0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> B;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
			min_height = min(min_height, map[i][j]);
			max_height = max(max_height, map[i][j]);
		}
	}

	int opt_time = INT_MAX, opt_height = 0;
	for(int i = min_height; i <= max_height; i++){
		if (solve(i)){
			if (opt_time >= now_time){
				opt_time = now_time;
				opt_height = i;
			}
		}
	}
	cout << opt_time << " " << opt_height << "\n";
}