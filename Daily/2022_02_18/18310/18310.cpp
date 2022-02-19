#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int max_val = 0, min_val = INT_MAX, cnt, num;
	cin >> cnt;
	vector <int> houses;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		houses.push_back(num);
	}
	sort(houses.begin(), houses.end());
	cout << houses[(cnt - 1) / 2] << "\n";

}

//13 mins

/*

1 3 5 5 5 8 10

*/