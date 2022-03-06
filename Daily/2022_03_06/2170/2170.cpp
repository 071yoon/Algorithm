#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num1, num2;
	vector <pair<int, int> > vec; //start and end
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num1 >> num2;
		vec.push_back(make_pair(num1, num2));
	}
	sort(vec.begin(), vec.end());
	int sum = 0;
	int start = vec[0].first, end = vec[0].second;
	for (int i = 1; i < cnt; ++i) {
		if (vec[i].first <= end)
			end = max(end, vec[i].second);
		else {
			sum += end - start;
			start = vec[i].first;
			end = vec[i].second;
		}
	}
	sum += end - start;
	cout << sum << '\n';
}