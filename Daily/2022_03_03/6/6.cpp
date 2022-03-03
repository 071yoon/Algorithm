#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <int> crops;

int solve(int lo, int hi){
	if (lo + 1 == hi)
		return max(crops[lo + 1], crops[hi]);
	int mid = (lo + hi) / 2;
	int select_left = *max_element(crops.begin() + lo, crops.begin() + mid) + solve(mid + 1, hi);
	int select_right = solve(lo, mid) + *max_element(crops.begin() + mid + 1, crops.begin() + hi);
	return (max(select_left, select_right));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int sz, num;

	cin >> sz;
	for(int i = 0; i < sz; i++){
		cin >> num;
		crops.push_back(num);
	}	
	cout << solve(0, sz - 1) << "\n";
}
//11mins 59sec