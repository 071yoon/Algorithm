#include <queue>
#include <iostream>
using namespace std;

int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cntr = 1;
	while (1){
		int sz;
		cin >> sz;
		if (sz == 0){
			return(0) ;
		}
		int mapp[125][125] = {0};
		int visited[125][125] = {0};
		queue <pair<int, int> > que;
		for(int i = 0; i < sz; i++){
			for(int j = 0; j < sz; j++){
				cin >> mapp[i][j];
				visited[i][j] = 987654321;
			}
		}
		que.push(make_pair(0, 0));
		visited[0][0] = mapp[0][0];
		while(!que.empty()){
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			for(int i = 0; i < 4; i++){
				int nx = x + directions[i][0];
				int ny = y + directions[i][1];
				if (nx >= 0 && nx < sz && ny >= 0 && ny < sz && visited[nx][ny] > visited[x][y] + mapp[nx][ny]){
					visited[nx][ny] = visited[x][y] + mapp[nx][ny];
					que.push(make_pair(nx, ny));
				}
			}
		}
		cout << "Problem " << cntr++ << ": " << visited[sz - 1][sz - 1] << "\n";
	}
}