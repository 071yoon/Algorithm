#include <iostream>
#include <string>
using namespace std;

int secret = 0, participants, rows;
bool flag;
string ans, goal;
string board[1001];
string up_down, down_up;

void board_down() {
  for (int i = 0; i < participants; i++) {
    up_down.push_back('x');
  }
  for (int player = 0; player < participants; player++) {
    int original = player;
    int start = player;
    // (0, player) start
    for (int j = 0; j < secret; j++) {
      // when left wall
      if (start == 0) {
        if (board[j][start] == '-') start++;
        continue;
      } else if (board[j][start] == '-') {
        start++;
      } else if (board[j][start - 1] == '-') {
        start--;
      } else {
        continue;
      }
    }
    up_down[start] = original + 'A';
  }
}

void board_up() {
  for (int i = 0; i < participants; i++) {
    down_up.push_back('x');
  }
  for (int player = 0; player < participants; player++) {
    char original = goal[player];
    int start = player;
    // (0, player) start
    for (int j = rows - 1; j > secret; j--) {
      // when left wall
      if (start == 0) {
        if (board[j][start] == '-') start++;
        continue;
      } else if (board[j][start] == '-') {
        start++;
      } else if (board[j][start - 1] == '-') {
        start--;
      } else {
        continue;
      }
    }
    down_up[start] = original;
  }
}

bool is_possible() {
  for (int player = 0; player < participants; player++) {
    char next;
    if (player == 0) {
      if (board[secret][player] == '-') {
        next = down_up[player + 1];
      } else {
        next = down_up[player];
      }
    } else {
      if (board[secret][player] == '-') {
        next = down_up[player + 1];
      } else if (board[secret][player - 1] == '-') {
        next = down_up[player - 1];
      } else {
        next = down_up[player];
      }
    }
    if (next != up_down[player]) return false;
  }
  return true;
}

void back_track(int cnt) {
  if (cnt == participants) {
    if (is_possible()) {
      flag = true;
      ans = board[secret];
    }
    return;
  }

  if (cnt == 0 || board[secret][cnt - 1] != '-') {
    board[secret][cnt] = '-';
    back_track(cnt + 1);
  }
  board[secret][cnt] = '*';
  back_track(cnt + 1);
  board[secret][cnt] = '?';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> participants >> rows >> goal;
  for (int i = 0; i < rows; i++) {
    cin >> board[i];
    if (board[i][0] == '?') secret = i;
  }

  board_down();
  board_up();
  back_track(0);
  if (ans.size() != 0) {
    cout << ans << "\n";
  } else {
    for (int i = 0; i < participants - 1; i++) {
      cout << "x";
    }
    cout << "\n";
  }
}