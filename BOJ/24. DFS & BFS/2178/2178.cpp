#include <iostream>
#include <utility>
#include <string>
#include <queue>

using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string arr[101];
	int dist[101][101];
	bool chk[101][101]; 
	
	queue<pair<int,int> > que;
	int n,m;

	cin >> n >> m;
	
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];	
	}
	
	dist[0][0] = 1;
	que.push(make_pair(0, 0));
	chk[0][0] = 1;
	
	while(!que.empty()){
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
		for(int dir = 0; dir < 4; dir++){ 
			int nx = y + dx[dir];
			int ny = x + dy[dir];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >=m)
				continue;
				
			if(arr[nx][ny] == '0' || chk[nx][ny])
				continue;
			
			dist[nx][ny] = dist[y][x] + 1;
			que.push(make_pair(nx, ny));
			chk[nx][ny] = 1;
			
		}
	}

	cout << dist[n - 1][m - 1];
	
	return 0; 

} 