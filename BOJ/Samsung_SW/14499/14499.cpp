#include <iostream>
#include <algorithm>
using namespace std;

int dice[6] = {0, 0, 0, 0, 0, 0};

void dice_change(int num){
	int a = dice[0]; int b = dice[1]; int c = dice[2]; int d = dice[3]; int e = dice[4]; int f = dice[5];
	
	if (num == 1){//east
		dice[0] = f;
		dice[2] = e;
		dice[4] = a;
		dice[5] = c;
	}
	else if (num == 2){//west
		dice[0] = e;
		dice[2] = f;
		dice[4] = c;
		dice[5] = a;
	}
	else if (num == 3){//north
		dice[0] = d;
		dice[1] = a;
		dice[2] = b;
		dice[3] = c;
	}
	else{//south
		dice[0] = b;
		dice[1] = c;
		dice[2] = d;
		dice[3] = a;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, x, y, K;
	int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
	int map[20][20] = {0};
	cin >> N >> M >> x >> y >> K;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}
	int order;
	for(int i = 0; i < K; i++){
		cin >> order;
		int new_x = x + direction[order - 1][0];
		int new_y = y + direction[order - 1][1];
		if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M){
			continue;
		}
		dice_change(order);
		cout << dice[2] << "\n";
		if (map[new_x][new_y] == 0){
			map[new_x][new_y] = dice[0];
		}
		else{
			dice[0] = map[new_x][new_y];
			map[new_x][new_y] = 0;
		}
		x = new_x;
		y = new_y;
	}
}