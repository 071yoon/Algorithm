#include <iostream>
#include <queue>
using namespace std;

int main() {
  int subin, sister;
  int time[100001] = {0};
  int min_time = 2e9;
  int cnt = 0;
  queue<int> que;

  cin >> subin >> sister;

  if (subin >= sister) {
    cout << subin - sister << "\n" << 1 << "\n";
    return 0;
  }

  time[subin] = 1;
  que.push(subin);
  while (!que.empty()) {
    int cur = que.front();
    que.pop();

    if (min_time < time[cur]) continue;

    for (int i = 0; i < 3; i++) {
      int next;
      if (i == 0) next = cur + 1;
      if (i == 1) next = cur - 1;
      if (i == 2) next = cur * 2;
      if (next < 0 || next > 100000) continue;

      if (next == sister) {
        min_time = time[cur];
        cnt++;
      }

      // first visit or different type of visit
      if (time[next] == 0 || time[next] == time[cur] + 1) {
        que.push(next);
        time[next] = time[cur] + 1;
      }
    }
  }

  cout << min_time << "\n" << cnt << "\n";
}