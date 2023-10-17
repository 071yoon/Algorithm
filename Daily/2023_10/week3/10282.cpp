#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void run_test_case() {
  int cmp_cnt, dep_cnt, start;
  // cost and computer
  priority_queue<pair<int, int> > pq;
  // computer and cost
  vector<pair<int, int> > vec[10001];
  // visited
  int dist[10001] = {0};

  cin >> cmp_cnt >> dep_cnt >> start;

  for (int i = 0; i < dep_cnt; i++) {
    int cmp1, cmp2, time;
    cin >> cmp1 >> cmp2 >> time;
    vec[cmp2].push_back(make_pair(cmp1, time));
  }

  for (int i = 0; i <= cmp_cnt; i++) {
    dist[i] = 2e9;
  }

  dist[start] = 0;

  pq.push(make_pair(0, start));
  while (!pq.empty()) {
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    for (int i = 0; i < vec[cur].size(); i++) {
      int next = vec[cur][i].first;
      int next_cost = cost + vec[cur][i].second;
      if (dist[next] > next_cost) {
        dist[next] = next_cost;
        pq.push(make_pair(-next_cost, next));
      }
    }
  }

  int ret_cnt = 0;
  int time = 0;
  for (int i = 0; i <= cmp_cnt; i++) {
    if (dist[i] != 2e9) {
      ret_cnt++;
      time = max(time, dist[i]);
    }
  }
  cout << ret_cnt << " " << time << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int cnt;
  cin >> cnt;
  for (int i = 0; i < cnt; i++) {
    run_test_case();
  }
}