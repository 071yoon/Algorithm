#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int row, col;
vector <pair<int, pair<int, int> > > CCTV;
int ans = INT_MAX;
int room[8][8] = {0};
int room_color[8][8] = {0};
int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void copy(int arr1[8][8], int arr2[8][8]){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			arr1[i][j] = arr2[i][j];
		}
	}
}

void check_empty(){
	int tmp = 0;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (room_color[i][j] == 0)
				tmp++;
		}
	}
	ans = min(tmp, ans);
}

void color_one(int x, int y, int target){
	int new_x = x + direction[target][0];
	int new_y = y + direction[target][1];
	if (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col && room[new_x][new_y] != 6){
		if (room_color[new_x][new_y] == 0)
			room_color[new_x][new_y] = 9;
		color_one(new_x, new_y, target);
	}
}

void color_two(int x, int y, int target){
	color_one(x, y, target);
	color_one(x, y, (target + 2) % 4);
}

void color_three(int x, int y, int target){
	color_one(x, y, target);
	color_one(x, y, (target + 1) % 4);
}

void color_four(int x, int y, int target){
	color_one(x, y, target);
	color_one(x, y, (target + 1) % 4);
	color_one(x, y, (target + 2) % 4);
}

void color_five(int x, int y, int target){
	for(int i = 0; i < 4; i++){
		color_one(x, y, (target + i) % 4);
	}
}

void deal_rooms(int cnt){
	if (cnt == CCTV.size()){
		check_empty();
		return ;
	}
	for(int i = 0; i < 4; i++){
		int tmp[8][8] = {0};
		copy(tmp, room_color);
		if (CCTV[cnt].first == 1){
			//color oen line in room_color
			color_one(CCTV[cnt].second.first, CCTV[cnt].second.second, i);
			deal_rooms(cnt + 1);
			copy(room_color, tmp);
		}
		else if (CCTV[cnt].first == 2){
			color_two(CCTV[cnt].second.first, CCTV[cnt].second.second, i);
			deal_rooms(cnt + 1);
			copy(room_color, tmp);
		}
		else if (CCTV[cnt].first == 3){
			color_three(CCTV[cnt].second.first, CCTV[cnt].second.second, i);
			deal_rooms(cnt + 1);
			copy(room_color, tmp);
		}
		else if (CCTV[cnt].first == 4){
			color_four(CCTV[cnt].second.first, CCTV[cnt].second.second, i);
			deal_rooms(cnt + 1);
			copy(room_color, tmp);
		}
		else{
			color_five(CCTV[cnt].second.first, CCTV[cnt].second.second, i);
			deal_rooms(cnt + 1);
			copy(room_color, tmp);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> room[i][j];
			if (room[i][j] >= 1 && room[i][j] <= 5)
				CCTV.push_back(make_pair(room[i][j], make_pair(i, j)));
		}
	}
	int cnt = 0;
	copy(room_color, room);
	deal_rooms(cnt);
	cout << ans << "\n";
}