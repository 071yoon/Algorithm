#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, trial, me, num;
	cin >> cnt >> trial >> me;
	vector <int> location;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		location.push_back(num);
	}
	int min_val = 987654321;
	for(int i = 0, j = trial - 1; j < cnt; i++, j++){
		min_val = max(abs(i - j), max(abs(i - me), abs(j - me)));
	}
	cout << min_val << "\n";
}
