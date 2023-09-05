#include <iostream>
#include <queue>
using namespace std;

// { current_break, { x, y } }
priority_queue<pair<int, pair<int, int> > > pq;
char board[101][101];
int dist[101][101] = {0};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  int r, c;
  string str;
  cin >> c >> r;
  for (int i = 0; i < r; i++) {
    cin >> str;
    for (int j = 0; j < c; j++) {
      dist[i][j] = 2e9;
      board[i][j] = str[j];
    }
  }
  dist[0][0] = 0;
  pq.push(make_pair(0, make_pair(0, 0)));
  while (!pq.empty()) {
    int cost = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    // cout << "cost:" << cost << " x:" << x << " y:" << y << "\n";
    pq.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dir[i][0];
      int ny = y + dir[i][1];
      if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
        int extra = board[nx][ny] == '1' ? 1 : 0;
        int nCost = cost + extra;
        // cout << "cost:" << nCost << " nx:" << nx << " ny:" << ny << "\n";
        if (nCost < dist[nx][ny]) {
          dist[nx][ny] = nCost;
          pq.push(make_pair(-nCost, make_pair(nx, ny)));
        }
      }
    }
  }
  cout << dist[r - 1][c - 1] << "\n";
}
