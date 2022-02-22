#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str1, str2;
	cin >> str1 >> str2;
	int min_val = 987654321;
	for(int i = 0; i <= str2.length() - str1.length(); i++){
		int tmp = 0;
		for(int j = 0; j < str1.length(); j++){
			if (str1[j] != str2[i + j]){
				tmp++;
			}
		}
		min_val = min(min_val, tmp);
	}
	cout << min_val << "\n";
}
//15mins 25sec