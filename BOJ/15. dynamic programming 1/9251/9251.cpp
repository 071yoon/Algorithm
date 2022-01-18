#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str1, str2;
	char arr1[1002] = {0};
	char arr2[1002] = {0};
	int dp[1002][1002] = {0};
	cin >> str1 >> str2;
   for (int i = 1; i <= str1.length(); i++){
        for (int j = 1; j <= str2.length(); j++){
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	cout << dp[str1.length()][str2.length()];
    return 0;
}