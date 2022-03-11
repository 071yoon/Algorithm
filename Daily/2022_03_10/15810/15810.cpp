#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long ppl, cnt, num;
	vector <long long> people;
	cin >> ppl >> cnt;
	for(int i = 0; i < ppl; i++){
		cin >> num;
		people.push_back(num);
	}
	long long lo = 0, hi = 1000000000001LL, ret = 1000000000001LL;
	while(lo <= hi){
		long long mid = (lo + hi) / 2;
		long long tmp = 0;
		for(int i = 0; i < ppl; i++){
			tmp += (mid / people[i]);
		}
		if (tmp >= cnt){
			ret = min(mid, ret);
			hi = mid - 1;
		}
		else{
			lo = mid + 1;
		}
	}
	cout << ret << "\n";
}