#include <iostream>
#include <string>
#define M 1234567891
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt;
	long long ret = 0;
	long long mul = 1;
	string str;
	cin >> cnt;
	cin >> str;
	for(int i = 0; i < cnt; i++){
		ret = (ret + (str[i] - 'a' + 1) * mul) % M;
		mul = (mul * 31) % M;
	}
	cout << ret << "\n";
}