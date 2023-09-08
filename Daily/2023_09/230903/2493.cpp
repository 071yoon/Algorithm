#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<pair<int, int> > st;
vector<int> ans_vec;

int will_return = 0;

void ans(int len, int loc) {
  while (!st.empty() && st.top().first < len) st.pop();
  if (st.empty())
    ans_vec.push_back(0);
  else
    ans_vec.push_back(st.top().second);
  st.push(make_pair(len, loc));
}

int main() {
  int cnt;
  cin >> cnt;

  for (int i = 0; i < cnt; i++) {
    int num;
    cin >> num;
    ans(num, i + 1);
  }
  for (int i = 0; i < cnt; i++) {
    cout << ans_vec[i] << " ";
  }
}