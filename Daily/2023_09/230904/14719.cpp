#include <iostream>
using namespace std;

int main() {
  int H, W;
  int arr[501];
  cin >> H >> W;
  for (int i = 0; i < W; i++) {
    cin >> arr[i];
  }
  int max_left = arr[0];
  int ans = 0;
  for (int i = 1; i < W; i++) {
    if (arr[i] > max_left) max_left = arr[i];
    int max_right = 0;
    for (int j = i + 1; j < W; j++) {
      if (arr[j] > max_right) max_right = arr[j];
    }
    if (max_right >= max_left) {
      if ((max_left - arr[i] > 0)) ans += max_left - arr[i];
    } else {
      if (max_right - arr[i] > 0) ans += max_right - arr[i];
    }
  }
  cout << ans << "\n";
}