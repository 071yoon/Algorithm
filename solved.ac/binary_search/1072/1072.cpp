#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long game, win;
	cin >> game >> win;
	long long percent = (win * 100) / game;
	if (percent >= 99){
		cout << "-1\n";
		return (0);
	}
	long long start = 0;
	long long end = INT_MAX;
	long long ret = 0;
	while(start <= end){
		long long mid = (start + end) / 2;
		if ((((win + mid) * 100) / (game + mid)) >= (percent + 1)){
			ret = mid;
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	cout << ret << "\n";
}