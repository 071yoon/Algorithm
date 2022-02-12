#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int alphabets[26] = {0};
	string str;
	string tmp1, tmp2;
	cin >> str;
	for(int i = 0; i < str.size(); i++){
		alphabets[str[i] - 'A']++;
	}
	for(int i = 0; i < 26; i++){
		if (alphabets[i] % 2 == 1){
			tmp1 += i + 'A';
		}
		for(int j = 0; j < alphabets[i] / 2; j++){
			tmp2 += i + 'A';
		}
	}
	if (tmp1.size() > 1)
		cout << "I'm Sorry Hansoo\n";
	else{
		cout << tmp2 << tmp1;
		reverse(tmp2.begin(), tmp2.end());
		cout << tmp2 << "\n";
	}
}