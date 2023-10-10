#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dp[501], original_data[501], parents[501];
vector<int> nodes[501];

int main() {
  int cnt;

  cin >> cnt;

  for (int i = 1; i <= cnt; i++) {
    int num;
    parents[i] = 0;

    cin >> original_data[i];
    dp[i] = original_data[i];

    while (1) {
      cin >> num;
      if (num == -1) break;
      nodes[num].push_back(i);
      parents[i]++;
    }
  }

  queue<int> que;

  for (int i = 1; i <= cnt; i++) {
    if (parents[i] == 0) que.push(i);
  }

  while (!que.empty()) {
    int cur = que.front();
    que.pop();
    for (int i = 0; i < nodes[cur].size(); i++) {
      int next = nodes[cur][i];
      if (--parents[next] == 0) que.push(next);
      dp[next] = max(dp[next], dp[cur] + original_data[next]);
    }
  }

  for (int i = 1; i <= cnt; i++) {
    cout << dp[i] << "\n";
  }
}