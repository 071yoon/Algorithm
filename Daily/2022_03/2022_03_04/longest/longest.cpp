#include <iostream>
#include <algorithm>
using namespace std;

int dp[3000][3000] = {0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str1, str2;
    int max_val = 0;
    cin >> str1 >> str2;
    for(int i = 0; i < str1.length(); i++){
        for(int j = 0; j < str2.length(); j++){
            if (str1[i] == str2[j]){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = max(1, dp[i - 1][j - 1] + 1);
                }
                max_val = max(max_val, dp[i][j]);
            }
        }
    }
    cout << max_val << "\n";
}