#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	int ret = 0;
	cin >> str;
	if (str[0] == 'd')
		ret = 10;
	else
		ret = 26;
	for(int i = 1; i < str.length(); i++){
		if (str[i] == 'd' && str[i - 1] == 'd')
			ret *= 9;
		else if (str[i] == 'c' && str[i - 1] == 'c')
			ret *= 25;
		else if (str[i] == 'd')
			ret *= 10;
		else
			ret *= 26;
	}
	cout << ret << "\n";
}