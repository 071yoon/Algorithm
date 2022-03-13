#include <cstring>
#include <iostream>
using namespace std;

bool run_test(int org[26], int test[26]){
	for(int i = 0; i < 26; i++){
		if (org[i] != test[i])
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int total;
	cin >> total;
	string str1, str2;
	while(total--){
		cin >> str1 >> str2;
		int org[26] = {0};
		for(int i = 0; i < str2.length(); i++){
			org[str2[i] - 'a']++;
		}
		int fflag = 1;
		int test[26] = {0};
		for(int i = 0, j = 0; j < str1.length(); j++){
			if (i + str2.length() - 1 != j){
				test[str1[j] - 'a']++;
				continue;
			}
			test[str1[j] - 'a']++;
			if (run_test(org, test)){
				cout << "YES\n";
				fflag = 0;
				break ;
			}
			test[str1[i] - 'a']--;
			i++;
		}
		if (fflag) cout << "NO\n";
	}
}