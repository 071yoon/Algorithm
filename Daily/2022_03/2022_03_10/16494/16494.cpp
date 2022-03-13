#include <iostream>
using namespace std;

int ints[20] = {0};
int dp[20] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int sz, cnt;
	cin >> sz >> cnt;
	for(int i = 0; i < sz; i++){
		cin >> ints[i];
	}
	dp[0] = ints[0];
	for(int i = 1; i < sz; i++){

	}
}
/*

10  -4  3   1   5   6   -35 12 21 -1
10  6   9   4   9   15  -35 12 33 32


*/