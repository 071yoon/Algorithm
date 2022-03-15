#include <iostream>
#include <vector>
using namespace std;

int days, cnt;
int ret = 0;
int starter = 1; int ender = 0;
vector <int> day;

void inputs(){
	int num;
	cin >> days >> cnt;
	for(int i = 0; i < days; i++){
		cin >> num;
		day.push_back(num);
		ender += num;
		starter = max(num, starter);
	}
}

void solve(){
	ret = ender;
	int mid = 0;
	while(starter <= ender){
		mid = (starter + ender) / 2;
		int money = mid, tmp = 1;
		for(int i = 0; i < days; i++){
			money = money - day[i];
			if (money <= 0){
				money = mid - day[i];
				tmp++;
			}
		}
		if (tmp <= cnt){
			ender = mid - 1;
		}
		else{
			starter = mid + 1;
		}
	}
	cout << mid << "\n";
}

int main(){
	inputs();
	solve();
}