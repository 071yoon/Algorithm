#include <iostream>
using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << (c * e - f * b) / (a * e - d * b) << " "
       << (c * d - a * f) / (b * d - a * e) << "\n";
}