#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt, num;
	cin >> cnt;
	vector <int> vec;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	int ret = 0;
	for(int i = 0; i < cnt; i++){
		ret = max(ret, vec[i] * (cnt - i));
	}
	cout << ret << "\n";
}