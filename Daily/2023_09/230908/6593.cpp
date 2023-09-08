#include <iostream>
#include <queue>
using namespace std;

int dir[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, 1}, {0, 0, -1}};

struct coord {
    int x;
    int y;
    int z;
};

int main(){
    int L, R, C;
    while(1) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) {
            return 0;
        }
        char board[31][31][31];
        int sx, sy, sz;
        int ex, ey, ez;
        int dist[31][31][31] = {0};
        queue <coord> que;

        for(int i = 0; i < L; i++) {
            for(int j = 0; j < R; j++) {
                string str;
                cin >> str;
                for(int k = 0; k < str.size(); k++) {
                    if (str[k] == 'S') {
                        sx = i;
                        sy = j;
                        sz = k;
                    } else if (str[k] == 'E') {
                        ex = i;
                        ey = j;
                        ez = k;
                    }
                    board[i][j][k] = str[k];
                }
            }
        }
        coord start;
        start.x = sx; start.y = sy; start.z= sz;
        que.push(start);
        dist[sx][sy][sz] = 1;
        while(!que.empty()){
            int x, y, z;
            x = que.front().x;
            y = que.front().y;
            z = que.front().z;
            que.pop();
            for(int i = 0; i < 6; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                int nz = z + dir[i][2];
                if (nx >= 0 && nx < L && ny >= 0 && ny < R && nz >= 0 && nz < C) {
                    if (dist[nx][ny][nz] == 0 && (board[nx][ny][nz] == '.' || board[nx][ny][nz] == 'E')) {
                        dist[nx][ny][nz] = dist[x][y][z] + 1;
                        coord newCoord;
                        newCoord.x = nx;
                        newCoord.y = ny;
                        newCoord.z = nz;
                        que.push(newCoord);
                    }
                }
            }
        }
        if (dist[ex][ey][ez] > 0) {
            cout << "Escaped in " << dist[ex][ey][ez] - 1 << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }

    }
}