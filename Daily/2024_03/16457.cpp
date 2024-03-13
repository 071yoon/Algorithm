#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, m, k;
bool visited[21] = {0};
int ans = 0;
vector<vector<int> > long_vec;

void back_track(int cnt, int cur) {
  if (cnt == n) {
    int tmp_cnt = 0;
    for (int i = 0; i < long_vec.size(); i++) {
      bool test = true;
      for (int j = 0; j < long_vec[i].size(); j++) {
        if (!visited[long_vec[i][j]]) {
          test = false;
          break;
        }
      }
      if (test) tmp_cnt++;
    }
    ans = max(ans, tmp_cnt);
    return;
  }
  if (cnt < n) {
    for (int i = cur; i <= 2 * n; i++) {
      visited[i] = true;
      back_track(cnt + 1, i + 1);
      visited[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) {
    vector<int> vec;
    for (int j = 0; j < k; j++) {
      int num1;
      cin >> num1;
      vec.push_back(num1);
    }
    long_vec.push_back(vec);
  }
  back_track(0, 1);
  cout << ans << "\n";
}