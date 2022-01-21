#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cnt, num, budget;
	vector <int> vec;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	cin >> budget;
	sort(vec.begin(), vec.end());
	int start = 0;
	int end = vec[cnt - 1];
	int result = 0;
	while(start <= end){
		int sum = 0;
		int mid = (start + end) / 2;
		for(int i = 0; i < cnt; i++){
			sum += min(vec[i], mid);
		}
		if (budget >= sum){
			result = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	cout << result << "\n";
}

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cnt, num;
	double sum = 0;
	vector <int> vec;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	cin >> sum;
	sum = sum / cnt;
	sort(vec.begin(), vec.end());
	for(int i = 0; i < cnt; i++){
		if (vec[i] >= sum){
			cout << (int)sum << "\n";
			return (0);
		}
		if (i == cnt - 1){
			cout << vec[cnt - 1] << "\n";
			return (0);
		}
		sum += (sum - vec[i]) / (cnt - i - 1);
	}
}
*/