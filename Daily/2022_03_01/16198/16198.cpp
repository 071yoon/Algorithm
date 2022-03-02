#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max_val = 0;
vector <int> vec;

void back_tracking(int cnt, int ret){
	if (vec.size() == 2){
		max_val = max(max_val, ret);
		return ;
	}
	for(int i = 1; i < vec.size() - 1; i++){
		int num = vec[i];
		int add = vec[i + 1] * vec[i - 1];
		vec.erase(vec.begin() + i);
		back_tracking(cnt + 1, ret + add);
		vec.insert(vec.begin() + i, num);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, num;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> num;
		vec.push_back(num);
	}
	back_tracking(0, 0);
	cout << max_val << "\n";
}