#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int possible = 0;
string tmp1, tmp2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> tmp1 >> tmp2;
	while(tmp2.length() >= tmp1.length()){
		if (tmp2 == tmp1){
			cout << "1\n";
			return (0);
		}
		if (tmp2[tmp2.size() - 1] == 'B'){
			tmp2.pop_back();
			reverse(tmp2.begin(), tmp2.end());
		}
		else{
			tmp2.pop_back();
		}
	}
	cout << "0\n";
}
// 11 mins