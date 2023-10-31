#include <iostream>
using namespace std;

int dir[2][2] = {{0, 1}, {1, 0}};
int board[65][65] = { 0 };
bool visited[65][65] = { 0 }; 
int sz;
bool flag = false;

void dfs(int x, int y) {
    if (x == sz - 1 && y == sz - 1) {
        flag = true;
        return ;
    }

    for (int i = 0; i < 2; i++) {
        int nx = x + dir[i][0] * board[x][y];
        int ny = y + dir[i][1] * board[x][y];
        if (nx < sz && nx >= 0 && ny < sz && ny >= 0 && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> sz;
    for (int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            cin >> board[i][j];
        }
    }

    visited[0][0] = true;
    dfs(0, 0);
    if (flag) cout << "HaruHaru";
    else cout << "Hing";

}