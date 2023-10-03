#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n, w, l;
  cin >> n >> w >> l;

  queue<int> truck;

  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    truck.push(w);
  }

  deque<pair<int, int> > bridge;

  int time = 0;
  while (!truck.empty() || !bridge.empty()) {
    int weight = 0;

    for (int i = 0; i < bridge.size(); i++) {
      bridge[i].first -= 1;
    }
    if (!bridge.empty() && bridge.front().first == 0) {
      bridge.pop_front();
    }
    for (int i = 0; i < bridge.size(); i++) {
      weight += bridge[i].second;
    }
    if (!truck.empty() && truck.front() + weight <= l && bridge.size() < w) {
      bridge.push_back(make_pair(w, truck.front()));
      truck.pop();
    }

    time++;
  }

  cout << time;
}