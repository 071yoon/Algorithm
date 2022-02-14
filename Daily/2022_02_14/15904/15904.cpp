#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	getline(cin, str);
	vector <char> chars;
	int u_flag = 0, c_flag = 0, p_flag = 0;
	for(int i = 0; i < str.length(); i++){
		if (str[i] == 'U' || str[i] == 'C' || str[i] == 'P'){
			chars.push_back(str[i]);
		}
	}
	int dp[1000] = {0};
	for(int i = 0; i < chars.size(); i++){
		if (chars[i] == 'U'){
			dp[i] = 1;
		}
		else if (chars[i] == 'P'){
			for(int j = 0; j < i; j++){
				if (dp[j] == 2){
					dp[i] = 3;
				}
			}
		}
		else{
			for(int j = 0; j < i; j++){
				if (dp[j] == 3){
					cout << "I love UCPC\n";
					return (0);
				}
				else if (dp[j] == 1){
					dp[i] = 2;
				}
			}
		}
	}
	cout << "I hate UCPC\n";
	
}