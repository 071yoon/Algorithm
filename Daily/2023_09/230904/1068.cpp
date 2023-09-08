#include <iostream>
#include <queue>
using namespace std;

bool nodes[51];
int parents[51];
queue<int> que[51];

void recur_del(int del) {
  nodes[del] = false;
  while (!que[del].empty()) {
    recur_del(que[del].front());
    que[del].pop();
  }
}

int main() {
  int sz, del;
  cin >> sz;
  for (int i = 0; i < sz; i++) {
    int parent;
    cin >> parent;
    if (parent == -1) {
      nodes[0] = true;
      continue;
    }
    que[parent].push(i);
    parents[i] = parent;
    nodes[i] = true;
  }
  cin >> del;
  recur_del(del);
  que[parents[del]].pop();
  int ans = 0;
  for (int i = 0; i < 51; i++) {
    if (nodes[i] && que[i].empty()) {
      ans++;
    }
  }
  cout << ans << "\n";
}