#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int K;
int tmp[500001] = {0};

void merge(vector<int> &arr, int p, int q, int r) {
  int i = p;
  int j = q + 1;
  int t = 1;
  while (i <= q && j <= r) {
    if (arr[i] <= arr[j]) {
      tmp[t++] = arr[i++];
    } else {
      tmp[t++] = arr[j++];
    }
  }
  while (i <= q) tmp[t++] = arr[i++];
  while (j <= r) tmp[t++] = arr[j++];
  i = p;
  t = 1;
  while (i <= r) {
    cnt++;
    if (cnt == K) {
      cout << tmp[t];
    }
    arr[i++] = tmp[t++];
  }
}

void merge_sort(vector<int> &arr, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(arr, p, q);
    merge_sort(arr, q + 1, r);
    merge(arr, p, q, r);
  }
}

int main() {
  vector<int> arr;
  int N;
  cin >> N >> K;
  arr.push_back(0);
  for (int i = 1; i <= N; i++) {
    int tmp;
    cin >> tmp;
    arr.push_back(tmp);
  }
  merge_sort(arr, 1, N);
  if (K > cnt) {
    cout << "-1\n";
  }
}