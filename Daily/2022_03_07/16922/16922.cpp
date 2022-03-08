#include <iostream>
using namespace std;

bool finaler[1001] = {0};
int used[4] = {0};
int adders[4] = {1, 5, 10, 50};
int num, ret = 0;

void back_tracking(int now, int val, int ind){
	if (now == num){
		if (!finaler[val]) ret++;
		finaler[val] = 1;
		return ;
	}
	for(int i = ind; i < 4; i++){
		int new_val = val + adders[i];
		back_tracking(now + 1, new_val, i);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> num;
	back_tracking(0, 0, 0);
	cout << ret << "\n";
}