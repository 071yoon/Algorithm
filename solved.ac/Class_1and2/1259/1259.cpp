#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string num;
	cin >> num;
	int flag = 1;
	while(num != "0"){
		flag = 1;
		int sz = num.length();
		for(int i = 0; i < sz / 2; i++){
			if (num[i] != num[sz - 1 - i]){
				cout << "no\n";
				flag = 0;
				break ;
			}
		}
		if (flag)
			cout << "yes\n";
		cin >> num;
	}
}