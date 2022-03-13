#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int gcd(int a, int b){
	while(b != 0){
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

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
	int gcd_num = gcd(vec[1] - vec[0], vec[2] - vec[1]);
	for(int i = 2; i < vec.size() - 1; i++){
		gcd_num = gcd(gcd_num, vec[i + 1] - vec[i]);
	}
	int ret = (vec[cnt - 1] - vec[0]) / gcd_num;
	ret -= cnt - 1;
	cout << ret << "\n";
}

/*

1 2 4 6 8
1 3 6 9 12

*/