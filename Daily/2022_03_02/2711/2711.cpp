#include <cstring>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	string str;
	cin >> cnt;
	while(cnt--){
		cin >> num;
		cin >> str;
		str.erase(str.begin() + num - 1);
		cout << str << "\n";
	}
}