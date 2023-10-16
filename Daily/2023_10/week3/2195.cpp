#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, p;
  int ans = 0;

  cin >> s >> p;
  for (int i = 0; i < p.size(); i++) {
    int min_cnt = 0;
    for (int j = 0; j < s.size(); j++) {
      int cnt = 0;
      int tmp_j = j;
      int tmp = i;
      while (s[tmp_j++] == p[tmp++]) {
        cnt++;
      }
      min_cnt = max(min_cnt, cnt);
    }
    i += min_cnt - 1;
    ans++;
  }
  cout << ans << "\n";
}