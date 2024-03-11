#include <iostream>
using namespace std;

bool visited[101][101] = {false};
char board[101][101];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int r, c;

int dfs(int x, int y) {
  int cnt = 1;
  // cout << x << y;
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0];
    int ny = y + dir[i][1];
    if (nx < 0 || nx >= c || ny < 0 || ny >= r || visited[nx][ny] ||
        board[nx][ny] != board[x][y]) {
      continue;
    } else {
      cnt += dfs(nx, ny);
    }
  }
  return cnt;
}

int main() {
  cin >> r >> c;
  int white = 0;
  int black = 0;

  for (int i = 0; i < c; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < r; j++) {
      board[i][j] = str[j];
    }
  }

  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++) {
      if (visited[i][j]) continue;
      int num = dfs(i, j);
      if (board[i][j] == 'W') {
        white += num * num;
      } else {
        black += num * num;
      }
    }
  }
  cout << white << " " << black << "\n";
  return 0;
}