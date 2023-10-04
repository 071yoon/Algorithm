#include <cstring>
#include <iostream>
using namespace std;

int board[9][9];

bool check_rule(int cnt) {
  int r = cnt / 9;
  int c = cnt % 9;
  for (int i = 0; i < 9; i++) {
    if (board[r][c] == board[r][i] && i != c) return false;
    if (board[r][c] == board[i][c] && i != r) return false;
  }

  int sr = (r / 3) * 3;
  int sc = (c / 3) * 3;
  for (int i = sr; i < sr + 3; i++) {
    for (int j = sc; j < sc + 3; j++) {
      if (i == r && j == c) continue;
      if (board[r][c] == board[i][j]) return false;
    }
  }

  return true;
}

void recur(int cnt) {
  if (cnt == 81) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << board[i][j];
      }
      cout << "\n";
    }
    exit(0);
  }
  int x = cnt / 9;
  int y = cnt % 9;
  if (board[x][y] == 0) {
    for (int i = 1; i <= 9; i++) {
      board[x][y] = i;
      if (check_rule(cnt)) recur(cnt + 1);
    }
    board[x][y] = 0;
  } else {
    recur(cnt + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 9; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < 9; j++) {
      board[i][j] = str[j] - '0';
    }
  }
  recur(0);
}