#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	cin >> cnt;
	vector <int> vec;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	if (vec[0] != 1){
		cout << 1 << "\n";
		return (0);
	}
	int sum = vec[0];
	for(int i = 1; i < cnt; i++){
		if (vec[i] > sum + 1){
			break ;
		}
		sum += vec[i];
	}
	cout << sum + 1 << "\n";
}

/*
1 1 2 3 6 7 30
다음 추의 무게가 합보다 작거나 같다면 굿
1, 2, 3, 6, 7, 30
2, 3, 4, 7, 8, 31

*/