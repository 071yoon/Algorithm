#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector <int> vec;
	int num, cnt = 0;
	cin >> num;
	int i = 0;
	while (num){
		vec.push_back(num % 10);
		num /= 10;
		cnt++;
	}
	sort(vec.begin(), vec.end());
	int sz = vec.size();
	for(int i = sz - 1; i >= 0; i--)
		cout << vec[i];
}
// 3 0 0 4 -> 0 0 0 0 0 0 0 0 3 4
// 4 3 0 0