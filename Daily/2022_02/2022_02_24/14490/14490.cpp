#include <string>
#include <iostream>
using namespace std;

int gcd(int a, int b){
	if (b == 0){
		return a;
	}
	else{
		return gcd(b, a % b);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	int num1 = 0, num2 = 0;
	getline(cin, str);
	int index = 0;
	while(str[index] != ':'){
		num1 = num1 * 10 + str[index++] - '0';
	}
	index++;
	while(index != str.length()){
		num2 = num2 * 10 + str[index++] - '0';
	}
	int gc = gcd(num1, num2);
	cout << num1 / gc << ":" << num2 / gc << "\n";
}