#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int parent[10001] = {0};
vector<pair<int, pair<int, int> > > vec;

int find(int x) {
  if (parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
  x = find(x);
  y = find(y);
  if (x > y)
    parent[y] = x;
  else
    parent[x] = y;
}

int main() {
  int V, E;
  int ans = 0;

  cin >> V >> E;

  for (int i = 1; i <= V; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < E; i++) {
    int first, second, cost;
    cin >> first >> second >> cost;
    vec.push_back(make_pair(cost, make_pair(first, second)));
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++) {
    if (find(vec[i].second.first) != find(vec[i].second.second)) {
      ans += vec[i].first;
      uni(vec[i].second.first, vec[i].second.second);
    }
  }
  cout << ans << "\n";
}