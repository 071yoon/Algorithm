#include <iostream>
#include <queue>
using namespace std;

int main() {
  int subin, sister;
  int dp[100001] = {0};
  int from[100001] = {0};
  queue<int> que;

  cin >> subin >> sister;
  dp[subin] = 1;
  que.push(subin);
  while (!que.empty()) {
    int front = que.front();
    que.pop();
    vector<int> tmp;
    tmp.push_back(front - 1);
    tmp.push_back(front + 1);
    tmp.push_back(front * 2);
    for (int i = 0; i < tmp.size(); i++) {
      if (tmp[i] >= 0 && tmp[i] <= 100000 && dp[tmp[i]] == 0) {
        dp[tmp[i]] = dp[front] + 1;
        from[tmp[i]] = front;
        que.push(tmp[i]);
      }
    }
  }

  vector<int> ans;
  int tmp = sister;
  ans.push_back(tmp);
  while (tmp != subin) {
    ans.push_back(from[tmp]);
    tmp = from[tmp];
  }
  cout << dp[sister] - 1 << "\n";
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
}