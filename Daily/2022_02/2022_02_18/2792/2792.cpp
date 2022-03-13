#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, num, min_val = 0;//children, colors
	cin >> N >> M;
	vector <int> vec;
	for(int i = 0; i < M; i++){
		cin >> num;
		min_val = max(min_val, num);
		vec.push_back(num);
	}
	int start = 1;
	int ender = min_val;
	int ret = 0;
	while(start <= ender){
		int mid = (start + ender) / 2;
		int people = 0;
		for(int i = 0; i < M; i++){
			people += vec[i] / mid;
			if (vec[i] % mid != 0){
				people++;
			}
		}
		if (people <= N){
			ret = mid;
			ender = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	cout << ret << "\n";

}
/*
7 people
1 4 4 7 7
1개면 23명
2개면 13명
3개면 11명
4개면 7명
5개면 7명
7개면 4명


total -> 23
23 / 7 = 3, 2
5명
1 4 4 4 4 3 3
4개면 7명
3개면 11명
2개면 13명
1개면 23명

*/