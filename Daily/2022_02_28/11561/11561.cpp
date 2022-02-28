#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	unsigned long long T, num;
	cin >> T;
	while(T--){
		cin >> num;
		unsigned long long answer = 0;
		unsigned long long low = 1; unsigned long long high = num;
		while(low <= high){
			unsigned long long mid = (low + high) / 2;
			if (mid * (mid + 1) <= 2 * num){
				answer = mid;
				low = mid + 1;
			}
			else{
				high = mid - 1;
			}
		}
		cout << answer << "\n";
	}
}
//45mins