#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector <int> plus;
	vector <int> minus;
	int hand, num, books, max_num = 0;
	cin >> books >> hand;
	for(int i = 0; i < books; i++){
		cin >> num;
		max_num = max(abs(num), max_num);
		if (num > 0){
			plus.push_back(num);
		}
		else
			minus.push_back(num * -1);
	}
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());
	int i = plus.size() - 1;
	long long sum = 0;
	while(i >= 0){
		sum += plus[i] * 2;
		i -= hand;
	}
	i = minus.size() - 1;
	while (i >= 0){
		sum += minus[i] * 2;
		i -= hand;
	}
	sum -= max_num;
	cout << sum << "\n";
}