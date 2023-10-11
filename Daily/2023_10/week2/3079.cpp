#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

long long work, ppl, num;
vector<int> vec;

bool test(long long mid) {
  long long ret = 0;
  for (int i = 0; i < vec.size(); i++) {
    ret += mid / vec[i];
  }
  if (ret >= ppl)
    return true;
  else
    return false;
}

int main() {
  cin >> work >> ppl;
  long long max_wait = 0;
  long long ret = 0;
  for (int i = 0; i < work; i++) {
    cin >> num;
    vec.push_back(num);
  }
  sort(vec.begin(), vec.end());
  long long st = 1, ed = ppl * vec[0];
  while (st <= ed) {
    long long mid = (st + ed) / 2;
    if (test(mid)) {
      if (ret > mid || ret == 0) {
        ret = mid;
      }
      ed = mid - 1;
    } else {
      st = mid + 1;
    }
  }
  cout << ret << "\n";
}