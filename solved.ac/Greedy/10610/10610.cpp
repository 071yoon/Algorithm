#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string num;
	cin >> num;
	sort(num.begin(), num.end());
	int i = 0;
	if (num[i] != '0'){
		cout << "-1\n";
		return (0);
	}
	long long sum = 0;
	for(int i = 0; i < num.size(); i++)
		sum += num[i];
	if (sum % 3 == 0){
		for(int i = num.size() - 1; i >= 0; i--){
			cout << num[i];
		}
	}
	else
		cout << "-1\n";
}