#include <iostream>
using namespace std;

int sz;
int board[500][500] = {0};
int rest = 0;
int tmp_sand = 0;

int single_spread(int nx, int ny, int value) {
  tmp_sand -= value;
  if (nx < 0 || ny >= sz || ny < 0 || ny >= sz) {
    rest += value;
  } else {
    board[nx][ny] += value;
  }
}

int last_spread(int nx, int ny) {
  if (nx < 0 || ny >= sz || ny < 0 || ny >= sz) {
    rest += tmp_sand;
  } else {
    board[nx][ny] += tmp_sand;
  }
}

int spread(int nx, int ny, int row_dir, int col_dir, int dust) {
  tmp_sand = dust;
  if (col_dir == 0) {
    // row
    single_spread(nx, ny + 2 * row_dir, (int)((dust * 5) / 100));
    single_spread(nx + 1, ny + row_dir, (int)(dust / 10));
    single_spread(nx - 1, ny + row_dir, (int)(dust / 10));
    single_spread(nx + 1, ny, (int)((dust * 7) / 100));
    single_spread(nx - 1, ny, (int)((dust * 7) / 100));
    single_spread(nx + 2, ny, (int)((dust * 2) / 100));
    single_spread(nx - 2, ny, (int)((dust * 2) / 100));
    single_spread(nx + 1, ny - row_dir, (int)(dust / 100));
    single_spread(nx - 1, ny - row_dir, (int)(dust / 100));
    last_spread(nx, ny + row_dir);
  } else {
    // col
    single_spread(nx + 2 * col_dir, ny, (int)((dust * 5) / 100));
    single_spread(nx + col_dir, ny + 1, (int)((dust) / 10));
    single_spread(nx + col_dir, ny - 1, (int)((dust) / 10));
    single_spread(nx, ny + 1, (int)((dust * 7) / 100));
    single_spread(nx, ny - 1, (int)((dust * 7) / 100));
    single_spread(nx, ny + 2, (int)((dust * 2) / 100));
    single_spread(nx, ny - 2, (int)((dust * 2) / 100));
    single_spread(nx - col_dir, ny + 1, (int)((dust) / 100));
    single_spread(nx - col_dir, ny - 1, (int)((dust) / 100));
    last_spread(nx + col_dir, ny);
  }
}

int main() {
  cin >> sz;
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      int num;
      cin >> num;
      board[i][j] = num;
    }
  }
  int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
  int direction = 0;
  int cnt = 1;
  int times = 2;
  int tmp = 1;
  int x = sz / 2;
  int y = sz / 2;

  while (1) {
    int nx = x + dir[direction % 4][0];
    int ny = y + dir[direction % 4][1];
    cout << "coordinate move from[" << x << "," << y << "] to [" << nx << ","
         << ny << "]\n";
    int dust = board[x][y];
    cout << "before==========================\n";
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        cout << board[i][j] << " ";
      }
      cout << "\n";
    }
    board[x][y] = 0;
    spread(nx, ny, dir[direction % 4][1], dir[direction % 4][0], dust);
    x = nx;
    y = ny;
    cout << "after==========================\n";
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        cout << board[i][j] << " ";
      }
      cout << "\n";
    }
    cout << "dust is " << rest << "\n";
    tmp--;
    if (tmp == 0) {
      times--;
      if (times == 0) {
        cnt++;
        times = 2;
      }
      tmp = cnt;
      direction++;
    }
    if (x == 0 && y == 0) {
      cout << "real done!\n[" << rest << "]\n";
      return 0;
    }
  }
  cout << rest << "\n";
}