//내 풀이 아니고 엄청 깔끔하게 적은 남의 풀이 쌔벼옴
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

int main() {

	cin >> N >> M;
	vector <int> arr(N);
	int lo = 0;
	int hi = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		hi += arr[i];
		lo = max(lo, arr[i]);
	}

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int cnt = 0;
		int temp_sum = 0;
		for (int i = 1; i <= N; i++) {
			if (temp_sum + arr[i] > mid) {
				cnt++;
				temp_sum = 0;
			}
			temp_sum += arr[i];
		}
		cnt++;
		if (cnt > M) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << lo << '\n';

	return 0;
}