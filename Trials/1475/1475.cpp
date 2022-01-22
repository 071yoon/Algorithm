#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string num;
	cin >> num;
	int m[10] = {0};
	for(int i = 0; i < num.length(); i++){
		if (num[i] == '9')
			m[6]++;
		else
			m[num[i] - '0']++;
	}
	if (m[6] % 2 == 1)
		m[6] = m[6] / 2 + 1;
	else
		m[6] /= 2;
	int max_val = 0;
	for(int i = 0; i < 10; i++){
		if (m[i] > max_val)
			max_val = m[i];
	}
	cout << max_val << "\n";
}