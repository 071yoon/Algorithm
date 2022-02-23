#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt;
	int dp[41] = {0};
	dp[0] = 1; dp[1] = 1; dp[2] = 2;
	for(int i = 3; i < 41; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int unique, num;
	cin >> cnt; cin >> unique;
	vector <int> vec;
	vec.push_back(0);
	for(int i = 0; i < unique; i++){
		cin >> num;
		vec.push_back(num);
	}
	vec.push_back(cnt + 1);
	int ret = 1;
	for(int i = 1; i < unique + 2; i++){
		ret = ret * (dp[vec[i] - vec[i - 1] - 1]);
	}
	cout << ret << "\n";
}
/*

1 -> 1

1 2 -> 2
2 1

1 2 3
1 3 2 -> 3
2 1 3

1 2 3 4
2 1 3 4
2 1 4 3 -> 5
1 2 4 3
1 3 2 4

1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 3 2 4 5
1 3 2 5 4 -> 8
2 1 3 4 5
2 1 3 5 4
2 1 4 3 5



*/