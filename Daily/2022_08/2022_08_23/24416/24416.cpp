#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int fibo[100] = {0};
	fibo[1] = 1;
	fibo[2] = 1;
	int num;
	cin >> num;
	for(int i = 3; i <= num; i++){
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[num] << " " << num - 2 << "\n";
}