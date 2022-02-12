#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector <int> plus;
	vector <int> minus;
	int cnt, num1, num2;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num1;
		if (num1 <= 0){
			minus.push_back(num1);
		}
		else
			plus.push_back(num1);
	}
	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end());
	int ret = 0;
	while(minus.size() >= 2){
		ret += minus[0] * minus[1];
		minus.erase(minus.begin());
		minus.erase(minus.begin());
	}
	for(int i = 0; i < minus.size(); i++){
		ret += minus[i];
	}
	while(plus.size() >= 2){
		int lst = plus.size() - 1;
		int bf_lst = plus.size() - 2;
		if (plus[lst] + plus[bf_lst] < plus[lst] * plus[bf_lst]){
			ret += plus[lst] * plus[bf_lst];
			plus.erase(plus.end() - 1);
			plus.erase(plus.end() - 1);
		}
		else
			break ;
	}
	for(int i = 0; i < plus.size(); i++){
		ret += plus[i];
	}
	cout << ret << "\n";
}