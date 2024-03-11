#include <iostream>
using namespace std;

int dir[8][2] = {{-1, 0}, {-1, -1}, {-1, 1}, {0, 1},
                 {0, -1}, {1, 0},   {1, -1}, {1, 1}};
// 0 ~ 19
int r = 19;
int c = 19;
int board[19][19];

bool check_valid(int x, int y, int num) {
  if (x < 0 || x >= r || y < 0 || y >= c || board[x][y] != num) return false;
  return true;
}

int check(int x, int y, int num) {
  // 대각1
  int diag1 = 0;
  int nx = x;
  int ny = y;
  for (int i = 0; i < 6; i++) {
    nx -= 1;
    ny -= 1;
    if (check_valid(nx, ny, num))
      diag1 += 1;
    else
      break;
  }
  nx = x;
  ny = y;
  for (int i = 0; i < 6; i++) {
    nx += 1;
    ny += 1;
    if (check_valid(nx, ny, num))
      diag1 += 1;
    else
      break;
  }

  // 대각2
  int diag2 = 0;
  nx = x;
  ny = y;
  for (int i = 0; i < 6; i++) {
    nx += 1;
    ny -= 1;
    if (check_valid(nx, ny, num))
      diag2 += 1;
    else
      break;
  }
  nx = x;
  ny = y;
  for (int i = 0; i < 6; i++) {
    nx -= 1;
    ny += 1;
    if (check_valid(nx, ny, num))
      diag2 += 1;
    else
      break;
  }

  // 상하
  int hori = 0;
  nx = x;
  ny = y;
  for (int i = 0; i < 6; i++) {
    nx -= 1;
    ny -= 0;
    if (check_valid(nx, ny, num))
      hori += 1;
    else
      break;
  }
  nx = x;
  ny = y;
  for (int i = 0; i < 6; i++) {
    nx += 1;
    ny += 0;
    if (check_valid(nx, ny, num))
      hori += 1;
    else
      break;
  }

  // 좌우
  int rl = 0;
  nx = x;
  ny = y;
  for (int i = 0; i < 6; i++) {
    nx -= 0;
    ny -= 1;
    if (check_valid(nx, ny, num))
      rl += 1;
    else
      break;
  }
  nx = x;
  ny = y;
  for (int i = 0; i < 6; i++) {
    nx += 0;
    ny += 1;
    if (check_valid(nx, ny, num))
      rl += 1;
    else
      break;
  }

  if (diag1 == 4 || diag2 == 4 || hori == 4 || rl == 4) {
    cout << board[x][y] << "\n" << x + 1 << " " << y + 1 << "\n";
    return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> board[i][j];
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (board[j][i] != 0)
        if (check(j, i, board[j][i])) {
          return 0;
        }
    }
  }
  cout << "0\n";
}