#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[4001][4001] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string A, B;
	int ret = 0;
	cin >> A >> B;
	for(int i = 0; i < A.length(); i++){
		for(int j = 0; j < B.length(); j++){
			if (A[i] == B[j]){
				if (i == 0 || j == 0){
					dp[i][j] = 1;
				}
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;
				ret = max(ret, dp[i][j]);
			}
		}
	}
	cout << ret << "\n";
}

/*
  E  C  A  D  A  D  A  B  R  B  C  R
A 0  0  1  0  1  0  1  0  0  0  0  0
B 0  0  0  0  0  0  0  2  0  1  0  0
R 0  0  0  0  0  0  0  0  3  0  0  1
A 0  0  1  0  1  0  1  0  0  0  0  0
C 0  1  0  0  0  0  0  0  0  0  1  0
A 0  0  2  0  1  0  1  0  0  0  0  0  
D 0  0  0  3  0  2  0  0  0  0  0  0
A 0  0  1  0  4  0  3  0  0  0  0  0


*/