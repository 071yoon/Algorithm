#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

bool remote[10] = {0};

int check_possible(int num){
	int cnt = 0;
	if (num == 0){
		if (remote[0])
			return (-1);
		else
			return (1);
	}
	while(num){
		if (remote[num % 10]){
			return (-1);
		}
		else
			cnt++;
		num /= 10;
	}
	return (cnt);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int goal_channel, remote_cnt, tmp, my_channel = 100;
	cin >> goal_channel;
	cin >> remote_cnt;
	for(int i = 0; i < remote_cnt; i++){
		cin >> tmp;
		remote[tmp] = 1;
	}
	int up_down = abs(goal_channel - my_channel);
	int  mini, ret = INT_MAX;
	for(int i = 0; i <= 1000000; i++){
		tmp = check_possible(i);
		if (tmp >= 0)
			mini = abs(i - goal_channel) + tmp;
		ret = min(mini, ret);
	}
	ret = min(ret, up_down);
	cout << ret << "\n";

}