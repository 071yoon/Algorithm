#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  vector<int> vec;
  int ans[11] = {0};

  cin >> N;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    vec.push_back(num);
  }

  for (int i = 1; i <= N; i++) {
    int cnt = vec[i - 1];
    for (int j = 0; j < N; j++) {
      if (ans[j]) continue;
      if (cnt == 0) ans[j] = i;
      cnt--;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
}