#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main(){
    int r, c;
    int sx, sy;
    queue <pair<int, int> > que;
    int board[1001][1001] = { 0 };
    int dist[1001][1001] = { 0 };

    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                sx = i;
                sy = j;
            }
        }
    }
    que.push(make_pair(sx, sy));
    dist[sx][sy] = 1;
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] == 0 || dist[nx][ny]) continue;
            dist[nx][ny] = dist[x][y] + 1;
            que.push(make_pair(nx, ny));
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if (dist[i][j]) {
                cout << dist[i][j] - 1 << " ";
            } else {
                if (board[i][j])
                cout << "-1 ";
                else cout << "0 ";
            }
        }
        cout << "\n";
    }


}