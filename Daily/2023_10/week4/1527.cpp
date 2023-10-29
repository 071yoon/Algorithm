#include <iostream>
using namespace std;

int A, B;
int ret = 0;

void sol(long long num) {
  if (num > B) return;
  if (A <= num && num <= B) {
    ret++;
  }
  sol(num * 10 + 4);
  sol(num * 10 + 7);
}

int main() {
  cin >> A >> B;
  sol(4);
  sol(7);
  cout << ret << "\n";
}