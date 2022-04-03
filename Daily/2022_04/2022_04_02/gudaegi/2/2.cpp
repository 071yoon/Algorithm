#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

void print_bin(int num){
	if (num == 0){
		cout << "0";
		return ;
	}
	string tmp = "";
	while(num){
		if (num % 2){
			tmp.push_back('1');
		}
		else tmp.push_back('0');
		num /= 2;
	}
	reverse(tmp.begin(), tmp.end());
	cout << tmp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num;
	cin >> num;
	for(int i = 0; i <= num; i++){
		print_bin(i);
	}
}