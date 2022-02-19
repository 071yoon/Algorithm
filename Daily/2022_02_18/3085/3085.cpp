#include <iostream>
#include <algorithm>
using namespace std;

int cnt, max_val = 0;
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char candy[50][50] = {0};

void check_max(){
	int tmp = 0;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < cnt; j++){
			char tmp_cl = candy[i][j];
			tmp = 0;
			if (tmp_cl == candy[i][j + 1]){
				while(j < cnt && tmp_cl == candy[i][j]){
					tmp++;
					j++;
				}
				j--;
				max_val = max(max_val, tmp);
			}
		}
	}
	for(int j = 0; j < cnt; j++){
		for(int i = 0; i < cnt; i++){
			char tmp_cl = candy[i][j];
			tmp = 0;
			if (tmp_cl == candy[i + 1][j]){
				while(j < cnt && tmp_cl == candy[i][j]){
					tmp++;
					i++;
				}
				i--;
				max_val = max(max_val, tmp);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < cnt; j++){
			cin >> candy[i][j];
		}
	}
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < cnt; j++){
			for(int k = 0; k < 4; k++){
				int ni = i + directions[k][0];
				int nj = j + directions[k][1];
				if (ni >= 0 && ni < cnt && nj >= 0 && nj < cnt && candy[i][j] != candy[ni][nj]){
					swap(candy[i][j], candy[ni][nj]);
					check_max();
					swap(candy[ni][nj], candy[i][j]);
				}
			}
		}
	}
	cout << max_val << "\n";
}