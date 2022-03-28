#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	if (c % 2 == 0){
		cout << a << "\n";
	}
	else{
		cout << (a^b) << "\n";
	}
}