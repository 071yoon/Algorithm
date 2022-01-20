#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long num;
	cin >> num;
	long long cnt = 1;
	long long ret = 1;
	while(num >= ret){
		cnt++;
		ret = (cnt * (cnt + 1)) / 2;
	}
	cout << cnt - 1 << "\n";
	
}