#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int row, col;
	vector <string> str;
	string tmp;
	cin >> row >> col;
	for(int i = 0; i < row; i++){
		cin >> tmp;
		str.push_back(tmp);
	}
	int lo = 0; int hi = row - 1; int last = row - 1;
	int ret = row - 1;
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		int flag = 1;
		set <string> st;
		for(int i = 0; i < col; i++){
			tmp = "";
			for(int j = mid; j < row; j++){
				tmp += str[j][i];
			}
			if (st.count(tmp)){
				flag = 0;
				break ;
			}
			else st.insert(tmp);
		}
		if (flag){ //decrase data
			lo = mid + 1;
		}
		else{ //increase data
			ret = mid - 1;
			hi = mid - 1;
		}
	}
	cout << ret << "\n";

}