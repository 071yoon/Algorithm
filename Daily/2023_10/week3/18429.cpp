#include <iostream>
#include <vector>
using namespace std;

vector<int> kits;
int ret = 0;
bool visited[9];
int weight_cnt, weight;

void back_track(int cnt, int sum) {
  if (cnt == kits.size()) {
    ret++;
    return;
  }

  sum -= weight;
  for (int i = 1; i <= kits.size(); i++) {
    if (visited[i]) continue;
    visited[i] = true;
    if (sum + kits[i - 1] >= 500) {
      back_track(cnt + 1, sum + kits[i - 1]);
    }
    visited[i] = false;
  }
}

int main() {
  cin >> weight_cnt >> weight;
  for (int i = 0; i < weight_cnt; i++) {
    int tmp;
    cin >> tmp;
    kits.push_back(tmp);
  }

  back_track(0, 500);
  cout << ret << "\n";
}