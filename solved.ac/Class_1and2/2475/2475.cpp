#include <iostream>
#include <math.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num[5];
	int ret;
	cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];
	ret = pow(num[0], 2) + pow(num[1], 2) + pow(num[2], 2) + pow(num[3], 2) + pow(num[4], 2);
	ret %= 10;
	cout << ret;
}