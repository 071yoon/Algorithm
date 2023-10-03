#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  int ans = 0;
  vector<int> vec;
  vector<int> ordered;

  cin >> N;
  cin >> K;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }
  sort(vec.begin(), vec.end());
  for (int i = 1; i < N; i++) {
    ordered.push_back(vec[i] - vec[i - 1]);
  }
  sort(ordered.begin(), ordered.end());

  for (int i = 0; i < N - K; i++) {
    ans += ordered[i];
  }
  cout << ans << "\n";
}