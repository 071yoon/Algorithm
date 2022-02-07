#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string word, str;
	int cnt = 0;
	getline(cin, word);
	getline(cin ,str);
	for(int i = 0; i < word.length(); i++){
		bool flag = 1;
		for(int j = 0; j < str.length(); j++){
			if (word[i + j] != str[j]){
				flag = 0;
				break ;
			}
		}
		if (flag){
			cnt++;
			i += str.length() - 1;
		}
	}
	cout << cnt << "\n";
}