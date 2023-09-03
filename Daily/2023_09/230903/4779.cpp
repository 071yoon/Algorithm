#include <iostream>
using namespace std;

void recur(int start, int end) {
  if (end == start) {
    cout << "-";
    return;
  }
  int cut = (end - start + 1) / 3;
  recur(start, start + cut - 1);
  for (int i = start + cut; i <= start + cut * 2 - 1; i++) {
    cout << " ";
  }
  recur(start + cut * 2, start + cut * 2 + cut - 1);
}

int main() {
  int N;
  while (cin >> N) {
    int tmp = 1;
    for (int i = 0; i < N; i++) {
      tmp *= 3;
    }
    recur(1, N);
    cout << "\n";
  }
}