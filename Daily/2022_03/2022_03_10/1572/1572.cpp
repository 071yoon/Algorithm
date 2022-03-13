#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K, num;
	cin >> N >> K;
	long long ret = 0;
	vector <int> vec;
	for(int i = 0; i < N; i++){
		cin >> num;
		vec.insert(lower_bound(vec.begin(), vec.end(), num), num);
		if (vec.size() == K){
			ret += vec[K / 2];
		}
		else if (vec.size() > K){
			vec.erase(vec.begin());
			ret += vec[K / 2];
		}
		for(int i = 0; i < vec.size(); i++){
			cout << vec[i] << " ";
		}
		cout << "\n";
	}
	cout << ret << "\n";
}
/*

3  4  5  6  7  8  9  10 11 12

[3, 4, 5]   4
[4, 5, 6]   5
[5, 6, 7]   6
[6, 7, 8]   7
[7, 8, 9]   8
[8, 9, 10]  9
[9, 10, 11] 10
[10, 11, 12]11


*/