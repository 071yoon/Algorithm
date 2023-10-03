#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
  int subin, sister;
  int dp[100001] = {0};
  int pos[100001] = {0};

  cin >> subin >> sister;
  queue<int> que;
  dp[subin] = 1;
  pos[subin] = 1;
  que.push(subin);
  while (!que.empty()) {
    int front = que.front();
    que.pop();
    vector<int> tmp;
    tmp.push_back(front - 1);
    tmp.push_back(front + 1);
    tmp.push_back(front * 2);
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 0; i < tmp.size(); i++) {
      if (tmp[i] >= 0 && tmp[i] <= 100000) {
        // first visit
        if (dp[tmp[i]] == 0) {
          dp[tmp[i]] = dp[front] + 1;
          pos[tmp[i]] = pos[front];
          que.push(tmp[i]);
          // second visit
        } else if (dp[tmp[i]] == dp[front] + 1) {
          pos[tmp[i]] += pos[front];
        }
      }
    }
  }
  cout << dp[sister] - 1 << "\n" << pos[sister] << "\n";
}