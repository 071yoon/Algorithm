#include <string>
#include <vector>

using namespace std;

bool map[51][51] = {false};
string orders = "dlru";
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, -1};
int end_x;
int end_y;
int max_x;
int max_y;
bool flag = false;
string answer = "";

int abs2(int a, int b) { return (a - b > 0 ? a - b : b - a); }

void dfs(int cur_x, int cur_y, int cur_count, int k, string tmp) {
  if (flag) return;
  if (cur_count == k) {
    if (end_x == cur_x && end_y == cur_y) {
      // STOP
      if (answer != "") return;
      answer = tmp;
      flag = true;
    }
    return;
  }
  for (int i = 0; i < 4; i++) {
    // d -> l -> r -> u
    int new_x = cur_x + dx[i];
    int new_y = cur_y + dy[i];
    if (new_x < 0 || new_x > max_x || new_y < 0 || new_y > max_y) continue;
    dfs(new_x, new_y, cur_count + 1, k, tmp + orders[i]);
  }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
  max_x = n - 1;
  max_y = m - 1;
  int start_x = x - 1;
  int start_y = y - 1;
  end_x = r - 1;
  end_y = c - 1;

  int mMove = abs2(r, x) + abs2(c, y);
  int rMove = abs2(k, mMove);

  if (rMove % 2 == 1 || mMove > k) {
    return "impossible";
  }
  dfs(start_x, start_y, 0, k, "");
  if (answer == "") return "impossible";
  return answer;
}