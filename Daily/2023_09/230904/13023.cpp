#include <iostream>
#include <vector>
using namespace std;

vector<int> rls[2001];
bool ans = false;

void dfs(int cnt, int person, bool visited[]) {
  if (cnt >= 4) {
    ans = true;
    return;
  }
  for (int i = 0; i < rls[person].size(); i++) {
    if (!visited[rls[person][i]]) {
      visited[rls[person][i]] = true;
      dfs(cnt + 1, rls[person][i], visited);
      visited[rls[person][i]] = false;
    }
  }
}

int main() {
  int ppl, relation;

  cin >> ppl >> relation;
  for (int i = 0; i < relation; i++) {
    int person1, person2;
    cin >> person1 >> person2;
    rls[person1].push_back(person2);
    rls[person2].push_back(person1);
  }
  for (int i = 0; i < ppl; i++) {
    bool visited[2001] = {false};
    visited[i] = true;
    dfs(0, i, visited);
    if (ans) {
      cout << "1\n";
      return 0;
    }
  }
  cout << "0\n";
}