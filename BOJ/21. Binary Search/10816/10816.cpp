#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> vec;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, num;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	cin >> M;
	int ret;
	for(int i = 0; i < M; i++){
		cin >> num;
		cout << upper_bound(vec.begin(), vec.end(), num) - lower_bound(vec.begin(), vec.end(), num) << " ";
	}
}