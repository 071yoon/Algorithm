#include <iostream>
#include <algorithm>
using namespace std;

int types[123456] = {0};
long long a[123456] = {0};
long long h[123456] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long rooms, atk;
	cin >> rooms >> atk;
	for(int i = 0; i < rooms; i++){
		cin >> types[i] >> a[i] >> h[i];
	}
	long long starter = 1; long long ender = 1e18;
	long long ret = 1e18;
	while (starter <= ender){
		long long attack = atk;
		long long mid = (starter + ender) / 2;
		long long max_hp = mid; 
		long long hp = max_hp;
		long long flag = 1;
		for(int i = 0; i < rooms; i++){
			long long health = h[i];
			if (types[i] == 1){
				if (attack >= health){
					continue ;
				}
				else{
					//attack is 10 and health 50 hp 40
					int times;
					if (health % attack == 0){
						times = health / attack;
					}
					else{
						times = health / attack + 1;
					}
					hp = hp - a[i] * (times - 1);
					if (hp <= 0){
						flag = 0;
						break ;//die
					}
				}
			}
			else{
				hp = hp + health;
				if (hp >= max_hp) hp = max_hp;
				attack = attack + a[i];
			}
		}
		if (flag){
			ret = min(ret, mid);
			ender = mid - 1;
		}
		else{
			starter = mid + 1;
		}
	}
	cout << ret << "\n";
}
//38mins 30sec