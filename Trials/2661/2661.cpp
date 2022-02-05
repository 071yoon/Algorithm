
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string str;
int cnt;

int checker(int cntr){
	for(int i = 1; i <= cntr / 2; i++){
		string a = str.substr(cntr - i, i);
		string b = str.substr(cntr - 2 * i, i);
		if (a.compare(b) == 0)
			return (0);
	}
	return (1);
}
int ender = 0;
void back_tracking(int cntr){
	if (ender == 1 || checker(cntr) == 0)
		return ;
	if (cntr == cnt){
		cout << str << "\n";
		ender = 1;
		return ;
	}
	for(int i = 0; i < 3; i++){
		str += '1' + i;
		back_tracking(cntr + 1);
		str.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> cnt;
	str.reserve(80);
	back_tracking(0);
}
