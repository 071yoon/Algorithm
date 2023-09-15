#include <iostream>
#include <stack>
using namespace std;

int main() {
  int N;
  long long ans = 0;
  stack<int> stk;

  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    while (!stk.empty() && stk.top() <= tmp) {
      stk.pop();
    }
    ans += (long long)stk.size();
    stk.push(tmp);
  }
  cout << ans << "\n";
}