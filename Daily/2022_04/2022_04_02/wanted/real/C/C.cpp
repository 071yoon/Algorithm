#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long datas[4] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int num;
	string str;
	cin >> num >> str;
	for(int i = 0; i < str.length(); i++){
		if (str[i] == 'W'){
			datas[0]++;
		}
		else if (str[i] == 'H'){
			datas[1] = (datas[1] + datas[0]) % 1000000007;
		}
		else if (str[i] == 'E'){
			if (datas[2] == 0){
				datas[2] = (datas[2] + datas[1]) % 1000000007;
				continue;
			}
			datas[3] = (datas[3] + datas[3] + datas[2]) % 1000000007;
			datas[2] = (datas[2] + datas[1]) % 1000000007;
		}
		// for(int i = 0; i < datas.size(); i++){
		// 	cout << datas[i] << " ";
		// }
		// cout << "\n";
	}
	if (datas[3]){
		cout << datas[3] << "\n";
	}
	else{
		cout << "0\n";
	}
}