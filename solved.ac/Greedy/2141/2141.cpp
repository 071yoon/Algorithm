#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt;
	long long num1, num2;
	double sum = 0;
	vector <pair<long long, long long> > vec;
	cin >> cnt;
	while(cnt--){
		cin >> num1 >> num2;
		vec.push_back(make_pair(num1, num2));
		sum += num2;
	}
	sort(vec.begin(), vec.end());
	sum /= 2;
	double new_sum = 0;
	for(int i = 0; i < vec.size(); i++){
		new_sum += vec[i].second;
		if (new_sum >= sum){
			cout << vec[i].first << "\n";
			return (0);
		}
	}
}