#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int cnt_0 = 0;
	int cnt_1 = 0;
	for(int i = 0; i < str.length(); i++){
		if (str[i] == '0'){
			cnt_0++;
			while(str[i] == '0')
				i++;
		}
	}
	for(int i = 0; i < str.length(); i++){
		if (str[i] == '1'){
			cnt_1++;
			while(str[i] == '1')
				i++;
		}
	}
	cout << min(cnt_0, cnt_1) << "\n";
}