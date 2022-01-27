#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long fibo[91] = {0};
	fibo[1] = 1;
	int num;
	cin >> num;
	for(int i = 2; i <= num; i++){
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[num] << "\n";
}