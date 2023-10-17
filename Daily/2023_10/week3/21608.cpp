#include <iostream>
#include <map>
#include <vector>
using namespace std;

int cnt;
int sum = 0;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int board[21][21] = {0};
vector<int> li;
map<int, vector<int> > m;

void input() {
  cin >> cnt;
  for (int i = 0; i < cnt * cnt; i++) {
    int num1, tmp;
    cin >> num1;
    li.push_back(num1);
    for (int i = 0; i < 4; i++) {
      cin >> tmp;
      m[num1].push_back(tmp);
    }
  }
}

int get_favors(int x, int y, int target) {
  int fav_cnt = 0;
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0];
    int ny = y + dir[i][1];
    if (nx < 0 || nx >= cnt || ny < 0 || ny >= cnt) continue;
    for (int j = 0; j < 4; j++) {
      if (m[target][j] == board[nx][ny]) {
        fav_cnt++;
      }
    }
  }
  return fav_cnt;
}

int get_empty(int x, int y) {
  int empty_cnt = 0;
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0];
    int ny = y + dir[i][1];
    if (nx < 0 || nx >= cnt || ny < 0 || ny >= cnt) continue;
    if (board[nx][ny] == 0) empty_cnt++;
  }
  return empty_cnt;
}

void set_position(int target) {
  int x = 0;
  int y = 0;
  int fav_cnt = -1;
  int empty_cnt = -1;
  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < cnt; j++) {
      if (board[i][j] != 0) continue;
      int fav = get_favors(i, j, target);
      if (fav > fav_cnt) {
        int empty = get_empty(i, j);
        empty_cnt = empty;
        x = i;
        y = j;
        fav_cnt = fav;
      } else if (fav == fav_cnt) {
        int empty = get_empty(i, j);
        if (empty > empty_cnt) {
          x = i;
          y = j;
          empty_cnt = empty;
        }
      }
    }
  }
  board[x][y] = target;
}

void get_sum() {
  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < cnt; j++) {
      int fav = get_favors(i, j, board[i][j]);
      if (fav == 1) {
        sum += 1;
      } else if (fav == 2) {
        sum += 10;
      } else if (fav == 3) {
        sum += 100;
      } else if (fav == 4) {
        sum += 1000;
      }
    }
  }
}

int main() {
  input();
  for (int i = 0; i < cnt * cnt; i++) {
    set_position(li[i]);
  }
  get_sum();
  cout << sum << "\n";
}