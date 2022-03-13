#include <cstring>
#include <iostream>
using namespace std;

string original_map[20];
int garo, sero, max_num = 0;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool alphabets[26] = {0};
void dfs(int cnt, int y, int x){
	max_num = max(max_num, cnt);
	for(int i = 0; i < 4; i++){
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (nx >= 0 && nx < garo && ny >= 0 && ny < sero){
			int alpha = original_map[ny][nx] - 'A';
			if (!alphabets[alpha]){
				alphabets[alpha] = 1;
				dfs(cnt + 1, ny, nx);
				alphabets[alpha] = 0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> sero >> garo;
	for(int i = 0; i < sero; i++){
		cin >> original_map[i];
	}
	alphabets[original_map[0][0] - 'A'] = 1;
	dfs(1, 0, 0);
	cout << max_num << "\n";
}

/*

alphabet[26] 을 마치 visited 처럼 사용
visited[][]도 물론 사용해야됨
DFS 로 시작에 좌측상단을 넣고 시작 
추가하면서 지나가며, dfs 에 카운트 증가하며, 최대 카운트는 항상 reset


*/
