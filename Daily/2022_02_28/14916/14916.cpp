#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cost;
	cin >> cost;
	int gijun = cost / 5;
	for(int i = gijun; i >= 0 ; i--){
		int tmp = cost;
		if ((cost - (i * 5)) % 2 == 0){
			cout << i + ((cost - (i * 5)) / 2) << "\n";
			return (0);
		}
	}
	cout << "-1\n";
}
//10mins