#include <iostream>
using namespace std;

int N, M, num;
long long cnt[1001];
long long sum, ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> num;
		sum += num;
		cnt[sum % M]++;
	}
	for(int i = 0; i <= 1000; i++)
		ans += cnt[i] * (cnt[i] - 1) / 2;
	cout << cnt[0] + ans << "\n";
}