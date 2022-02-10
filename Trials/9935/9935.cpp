#include <iostream>
#include <cstring>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str, bomb, ret;
	cin >> str;
	cin >> bomb;
	for(int i = 0; i < str.size(); i++){
		ret += str[i];
		if (ret[ret.size() - 1] == bomb[bomb.size() - 1] && ret.size() >= bomb.size()){
			int index = ret.size() - 1;
			int flag = 1;
			for(int j = bomb.size() - 1; j >= 0; j--){
				if (ret[index] != bomb[j]){
					flag = 0;
					break ;
				}
				index--;
			}
			if (flag){
				for(int j = bomb.size() - 1; j >= 0; j--)
					ret.pop_back();
			}
		}
	}
	if (ret == "")
		cout << "FRULA\n";
	else
		cout << ret << "\n";
}