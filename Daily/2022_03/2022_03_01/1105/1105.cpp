#include <string>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str1, str2;
	cin >> str1 >> str2;
	if (str1.length() != str2.length()){
		cout << "0\n";
		return (0);
	}
	int i = 0;
	int ret = 0;
	while(i < str1.length() && str1[i] == str2[i]){
		if (str1[i] == '8')
			ret++;
		i++;
	}
	cout << ret << "\n";
}
/*
8808 8880

*/