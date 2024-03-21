#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  /**
   * 0. 현재 불 위치 + 상근이 위치 저장
   * 1. 불 전진 (벽만 아니면 기존 맵 수정)
   * 2. 상근이 전진 (만약 벽이거나 불이면 stop)
   *
   */
  vector<pair<int, int> > fire_vec;
  vector<pair<int, int> > sang_vec;
  int tc;
  cin >> tc;
  for (int ce = 0; ce < tc; ce++) {
    char board[1001][1001] = {0};
    int r, c;
    string str;
    fire_vec.clear();
    sang_vec.clear();
    int cnt = 0;
    bool isEnd = false;

    cin >> r >> c;
    for (int j = 0; j < c; j++) {
      cin >> str;
      for (int k = 0; k < r; k++) {
        board[j][k] = str[k];
        if (str[k] == '*') {
          // 불
          fire_vec.push_back(make_pair(j, k));
        } else if (str[k] == '@') {
          // 상근
          sang_vec.push_back(make_pair(j, k));
          if (j == 0 || j == c - 1 || k == 0 || k == r - 1) {
            isEnd = true;
            cout << 1 << "\n";
          }
        }
      }
    }
    while (!sang_vec.empty()) {
      if (isEnd) break;
      // 불 먼저 이동
      vector<pair<int, int> > fire_tmp;
      for (int i = 0; i < fire_vec.size(); i++) {
        int x = fire_vec[i].first;
        int y = fire_vec[i].second;
        for (int k = 0; k < 4; k++) {
          int nx = x + dir[k][0];
          int ny = y + dir[k][1];
          if (nx >= c || nx < 0 || ny >= r || ny < 0) continue;
          if (board[nx][ny] == '*' || board[nx][ny] == '#') continue;
          board[nx][ny] = '*';
          // cout << "pushing ==> " << nx << " " << ny << "\n";
          fire_tmp.push_back(make_pair(nx, ny));
        }
      }
      fire_vec = fire_tmp;

      // 상근이 이동
      vector<pair<int, int> > sang_tmp;
      for (int i = 0; i < sang_vec.size(); i++) {
        int x = sang_vec[i].first;
        int y = sang_vec[i].second;
        for (int k = 0; k < 4; k++) {
          int nx = x + dir[k][0];
          int ny = y + dir[k][1];
          if (nx >= c || nx < 0 || ny >= r || ny < 0) continue;
          if (board[nx][ny] == '*' || board[nx][ny] == '#' ||
              board[nx][ny] == '@')
            continue;
          board[nx][ny] = '@';
          if (nx == c - 1 || ny == r - 1 || nx == 0 || ny == 0) {
            isEnd = true;
            cout << cnt + 2 << "\n";
            break;
          }
          sang_tmp.push_back(make_pair(nx, ny));
        }
      }
      // for (int i = 0; i < c; i++) {
      //   for (int j = 0; j < r; j++) {
      //     cout << board[i][j];
      //   }
      //   cout << "\n";
      // }
      cnt += 1;
      sang_vec = sang_tmp;
    }
    if (!isEnd) {
      cout << "IMPOSSIBLE\n";
    }
  }
}