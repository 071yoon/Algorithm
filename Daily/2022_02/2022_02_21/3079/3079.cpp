#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

long long work, ppl, num;
vector <int> vec;

bool test(long long mid){
	long long ret = 0;
	for(int i = 0; i < vec.size(); i++){
		ret += mid / vec[i];
	}
	if (ret >= ppl)
		return (1);
	else
		return (0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> work >> ppl;
	long long max_wait = 0;
	for(int i = 0; i < work; i++){
		cin >> num;
		max_wait = max(num, max_wait);
		vec.push_back(num);
	}
	long long st = 1, ed = max_wait * ppl;
	long long ret = 1000000000000000001;
	while(st <= ed){
		long long mid = (st + ed) / 2;
		if (test(mid)){
			ret = min(mid, ret);
			ed = mid - 1;
		}
		else{
			st = mid + 1;
		}
	}
	cout << ret << "\n";
}
/*
2  3  3  4  6  8  9
--------------------
2  3  3  4  6  8  9
4  6  6  8  12 16 18 
6  9  9  12 18 24 27

*/