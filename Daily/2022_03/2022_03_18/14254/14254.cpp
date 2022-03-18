#include <iostream>
#include <cstring>
using namespace std;

string str;
int num, ans;

void inputs(){
	cin >> str;
	cin >> num;
}

void solution(){
	string str1 = str.substr(0 , num);
	string str2 = str.substr(str.size() - num, num);
	ans = 0;
	cout << str1 << ":" << str2 << "\n";
	for(int i = 0; i < str1.size(); i++){
		if (str1[i] != str2[i]) ans++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solution();
	cout << ans << "\n";
}