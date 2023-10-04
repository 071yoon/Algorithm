#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int ans = 2e9;
  vector<pair<int, int> > vec;

  int cnt;
  cin >> cnt;
  for (int i = 0; i < cnt; i++) {
    int a, b;
    cin >> a >> b;
    vec.push_back(make_pair(a, b));
  }

  for (int i = 1; i < (1 << cnt); i++) {
    int a = 1, b = 0;
    for (int x = 0; x < cnt; x++) {
      if (i & (1 << x)) {
        a *= vec[x].first;
        b += vec[x].second;
      }
    }
    ans = min(ans, abs(a - b));
  }
  cout << ans << "\n";
}