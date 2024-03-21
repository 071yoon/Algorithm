#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int course_cnt, cds;
  vector<int> vec;
  cin >> course_cnt >> cds;
  for (int i = 0; i < course_cnt; i++) {
    int tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }
  int start = 0;
  int end = 2e9;
  int res = 0;
  while (start <= end) {
    bool flag = true;
    int mid = (start + end) / 2;
    int sum = 0;
    int cd_cnt = 0;
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] > mid) {
        flag = false;
        break;
      }
      if (sum + vec[i] > mid) {
        sum = 0;
        cd_cnt++;
      }
      sum += vec[i];
    }
    if (sum) cd_cnt++;
    if (!flag || cd_cnt > cds) {
      start = mid + 1;
    } else {
      res = mid;
      end = mid - 1;
    }
  }
  cout << res << "\n";
}