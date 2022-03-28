#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num;
	cin >> num;
	int cnt = 0;
	while(num){
		if (num % 2) cnt++;
		num /= 2;
	}
	cout << cnt << "\n";
}