#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, num;
	cin >> N >> M;
	vector <int> vec;
	for(int i = 0; i < N; i++){
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i < M; i++){
		cin >> num;
		auto it = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
		if (it < N && vec[it] == num){
			cout << it << "\n";
		}
		else{
			cout << "-1\n";
		}
	}
}