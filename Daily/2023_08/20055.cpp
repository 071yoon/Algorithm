#include <iostream>
#include <queue>
using namespace std;

int n, k;
deque<pair<int, int> > conveyor;

int main(void) {
  cin >> n >> k;

  for (int i = 0; i < 2 * n; i++) {
    int d;
    cin >> d;
    conveyor.push_back(make_pair(d, 0));
  }

  int step = 1;

  while (1) {
    // 1st
    conveyor.push_front(conveyor.back());
    conveyor.pop_back();
    conveyor[n - 1].second = 0;

    // 2nd
    for (int i = n - 2; i >= 0; i--) {
      if (conveyor[i].second == 1 && conveyor[i + 1].second == 0 &&
          conveyor[i + 1].first > 0) {
        conveyor[i].second = 0;
        conveyor[i + 1].second = 1;
        conveyor[i + 1].first--;
      }
    }
    conveyor[n - 1].second = 0;

    // 3rd
    if (conveyor[0].first > 0 && conveyor[0].second == 0) {
      conveyor[0].second = 1;
      conveyor[0].first--;
    }

    // 4th
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
      if (conveyor[i].first <= 0) cnt++;
    }
    if (cnt >= k) {
      cout << step;
      return 0;
    }
    step++;
  }

  return 0;
}