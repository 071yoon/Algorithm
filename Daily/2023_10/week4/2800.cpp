#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool visited[201] = {false};
string str;
stack<int> stk;
vector<pair<int, int> > vec;
set<string> s;

void dfs(int cnt, vector<pair<int, int> > cur) {
  if (cnt == vec.size()) {
    // do what i need to do
    string tmp;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '(') {
        for (int j = 0; j < cur.size(); j++) {
          if (cur[j].first == i) {
            // found
            tmp.push_back('(');
          }
        }
      } else if (str[i] == ')') {
        for (int j = 0; j < cur.size(); j++) {
          if (cur[j].second == i) {
            tmp.push_back(')');
          }
        }
      } else {
        tmp.push_back(str[i]);
      }
    }
    s.insert(tmp);
    return;
  }
  dfs(cnt + 1, cur);
  cur.push_back(make_pair(vec[cnt].first, vec[cnt].second));
  dfs(cnt + 1, cur);
}

int main() {
  cin >> str;

  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '(') {
      stk.push(i);
    } else if (str[i] == ')') {
      int tmp = stk.top();
      stk.pop();
      vec.push_back(make_pair(tmp, i));
    }
  }

  vector<pair<int, int> > cur;
  dfs(0, cur);

  for (auto it = ++s.begin(); it != s.end(); it++) {
    cout << *it << "\n";
  }
}