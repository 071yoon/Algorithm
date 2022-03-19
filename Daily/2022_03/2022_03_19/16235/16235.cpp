#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info{
	vector <int> tree;
	int yangbun;
};
int sz, tree_cnt, years;
int init[10][10] = {0};
int dir[8][2] = {{0, 1}, {0, -1}, {1, 1}, {1, -1}, {1, 0}, {-1, 0}, {-1, 1}, {-1, -1}};
info board[10][10];

void inputs(){
	cin >> sz >> tree_cnt >> years;
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			board[i][j].yangbun = 5;
			cin >> init[i][j];
		}
	}
	int x, y, tree_year;
	for(int i = 0; i < tree_cnt; i++){
		cin >> x >> y >> tree_year;
		board[x - 1][y - 1].tree.push_back(tree_year);
	}
}

void spring(){
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			sort(board[i][j].tree.begin(), board[i][j].tree.end());
			int tmp_dead = 0;
			vector <int> tmp;
			for(int k = 0; k < board[i][j].tree.size(); k++){
				if (board[i][j].yangbun < board[i][j].tree[k]){ //die
					tmp_dead += (board[i][j].tree[k] / 2);
				}
				else{
					board[i][j].yangbun -= board[i][j].tree[k];
					tmp.push_back(board[i][j].tree[k] + 1);
				}
			}
			board[i][j].tree = tmp;
			board[i][j].yangbun += tmp_dead;
		}
	}
}

void fall(){
	int tmp[10][10] = {0};
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			for(int k = 0; k < board[i][j].tree.size(); k++){
				if (board[i][j].tree[k] % 5 == 0){
					for(int r = 0; r < 8; r++){
						int ni = i + dir[r][0];
						int nj = j + dir[r][1];
						if (ni < 0 || ni >= sz || nj < 0 || nj >= sz) continue;
						tmp[ni][nj] += 1;
					}
				}
			}
		}
	}
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			while(tmp[i][j]){
				board[i][j].tree.push_back(1);
				tmp[i][j]--;
			}
		}
	}
}

void winter(){
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			board[i][j].yangbun += init[i][j];
		}
	}
}

void solve(){
	spring();
	fall();
	winter();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	for(int i = 0; i < years; i++){
		solve();
	}
	int ans = 0;
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			ans += board[i][j].tree.size();
		}
	}
	cout << ans << "\n";
}