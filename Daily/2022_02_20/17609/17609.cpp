#include <stack>
#include <iostream>
#include <string>
using namespace std;

bool is_pali(string str){
	int starter = 0;
	int ender = str.length() - 1;
	while (starter <= ender){
		if (str[starter++] != str[ender--]) return (false);
	}
	return (true);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt;
	cin >> cnt;
	string str;
	for(int i = 0; i < cnt; i++){
		cin >> str;
		if (is_pali(str)){
			cout << "0\n";
		}
		else{
			int starter = 0;
			int ender = str.length() - 1;
			while(starter <= ender){
				if (str[starter] != str[ender]){
					if (is_pali(str.substr(starter + 1, ender - starter))){
						cout << "1\n";
						break ;
					}
					else if (is_pali(str.substr(starter, ender - starter))){
						cout << "1\n";
						break ;
					}
					else{
						cout << "2\n";
						break ;
					}
				}
				starter++;
				ender--;
			}
		}
	}
}
/*
31 mins

*/