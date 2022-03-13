#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	if (num1 == num2 && num1 == num3){
		cout << 10000 + num1 * 1000 << "\n";
	}
	else if (num1 == num2 && num1 != num3){
		cout << 1000 + num1 * 100 << "\n";
	}
	else if (num1 == num3 && num1 != num2){
		cout << 1000 + num1 * 100 << "\n";
	}
	else if (num2 == num3 && num1 != num2){
		cout << 1000 + num2 * 100 << "\n";
	}
	else{
		int tmp = max(num1, num2);
		tmp = max(tmp, num3);
		cout << 100 * tmp << "\n";
	}
}