#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int game_sz;
int apple_cnt, direc_cnt;
int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};//RRRR
deque <pair<int, int> > snake;
vector <pair<int, int> > apple_vec;

int check_apple(int head_x, int head_y){//if apple -> return 1
	for(int i = 0; i < apple_vec.size(); i++){
		if (apple_vec[i].first == head_x && apple_vec[i].second == head_y){
			apple_vec.erase(apple_vec.begin() + i);
			return (1);
		}
	}
	return (0);
}

int check_tail(){//check and if bump -> return 1
	for(int i = 1; i < snake.size(); i++){
		if ((snake.front().first == snake[i].first) && (snake.front().second == snake[i].second))
			return (1);
	}
	return (0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> game_sz >> apple_cnt;
	int tmp_x, tmp_y;
	char direc_c;
	deque <pair<int, char> > direc_vec;
	for(int i = 0; i < apple_cnt; i++){
		cin >> tmp_x >> tmp_y;
		apple_vec.push_back(make_pair(tmp_x, tmp_y));
	}
	cin >> direc_cnt;
	for(int i = 0; i < direc_cnt; i++){
		cin >> tmp_x >> direc_c;
		direc_vec.push_back(make_pair(tmp_x, direc_c));
	}
	int ret = 1;
	int x = 1; int y = 1;
	int dir_i = 0;
	int new_head[2] = {0, 0};
	snake.push_back(make_pair(1, 1));
	while (1){
		new_head[0] = snake.front().first + direction[dir_i][0];
		new_head[1] = snake.front().second + direction[dir_i][1];
		if (new_head[0] > game_sz || new_head[0] < 1 || new_head[1] > game_sz || new_head[1] < 1){
			break ;
		}
		snake.push_front(make_pair(new_head[0], new_head[1]));
		if (check_tail()){
			break ;
		}
		if (!check_apple(new_head[0], new_head[1])){
			snake.pop_back();
		}
		if (ret == direc_vec.front().first){
			char direc_c = direc_vec.front().second;
			direc_vec.pop_front();
			if (direc_c == 'D'){
				dir_i++;
				if (dir_i == 4)
					dir_i = 0;
			}
			else{
				dir_i--;
				if (dir_i == -1)
					dir_i = 3;
			}
		}
		ret += 1;
	}
	cout << ret << "\n";
}