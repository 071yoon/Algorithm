#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, pair<int, int> > > vec;
int parent[1001] = {0};

int find(int x) {
  if (parent[x] == x) return x;
  return (parent[x] = find(parent[x]));
}

void un(int x, int y) {
  x = find(x);
  y = find(y);
  if (x > y)
    parent[x] = y;
  else
    parent[y] = x;
}

int main() {
  int computer_cnt;
  int cnt;

  cin >> computer_cnt >> cnt;

  for (int i = 1; i <= computer_cnt; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < cnt; i++) {
    int first, second, cost;
    cin >> first >> second >> cost;
    vec.push_back(make_pair(cost, make_pair(first, second)));
  }
  sort(vec.begin(), vec.end());

  int ans = 0;
  for (int i = 0; i < vec.size(); i++) {
    if (find(vec[i].second.first) != find(vec[i].second.second)) {
      un(vec[i].second.first, vec[i].second.second);
      ans += vec[i].first;
    }
  }
  cout << ans << "\n";
}