#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int row, col;
	int dist[100][100] = {0};
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	struct coord {
		int x;
		int y;
	};
	queue<coord> que;
	string arr[100];
	cin >> row >> col;
	for(int i = 0; i < row; i++){
		cin >> arr[i];
	}
	coord start;
	start.x = 0;
	start.y = 0;
	que.push(start);
	dist[0][0] = 1;
	int answer = 0;
	while(!que.empty()){
		int newX = que.front().x;
		int newY = que.front().y;
		if(newX == row - 1 && newY == col - 1){
			answer = dist[newX][newY];
			cout << answer << "\n";
			return 0;
		}
		que.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = newX + dx[dir];
			int ny = newY + dy[dir];
			if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
			if(arr[nx][ny] == '0') continue;
			if(dist[nx][ny] != 0) continue;
			dist[nx][ny] = dist[newX][newY] + 1;
			coord next;
			next.x = nx;
			next.y = ny;
			que.push(next);
		}
	}
	cout << "no answer" << "\n";


	// arr[0] => 101111
	// arr[1] => 101010
	// cout << arr[0] << "\n" << arr[1];

}