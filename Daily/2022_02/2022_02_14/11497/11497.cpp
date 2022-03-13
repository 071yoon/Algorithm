#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	cin >> cnt;
	while(cnt--){
		cin >> num;
		vector <int> vec;
		for(int i = 0; i < num; i++){
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		int ret = 0;
		sort(vec.begin(), vec.end());
		for(int i = 1; i < num - 1; i++){
			ret = max(ret, vec[i + 1] - vec[i - 1]);
		}
		cout << ret << "\n";
	}
}
/*

정렬을 할 떄, 내 기준에서 양옆으로 최소값을 정렬을 해줄것이다. -> 
즉 정렬 후에 나 기준 왼쪽 오른쪽의 최대값
10 10 11 11 12 12 13
*/