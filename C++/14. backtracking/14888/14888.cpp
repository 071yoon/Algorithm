#include <iostream>
#include <vector>

using namespace std;
vector <int> vec;
int op[4];
int ret = 0;
int mini = 1000000000;
int maxi = -1000000000;
int total = 0;

int ops(int cnt, int ret, int index){
	if (index == cnt){
		total++;
		if (ret > maxi)
			maxi = ret;
		if (ret < mini)
			mini = ret;
		return (0);
	}
	for(int i = 0; i < 4; i++){
		int sender;
		if (op[i] > 0){
			op[i]--;
			if (i == 0){
				sender = ret + vec[index];
				ops(cnt, sender, index + 1);
			}
			else if (i == 1){
				sender = ret - vec[index];
				ops(cnt, sender, index + 1);
			}
			else if (i == 2){
				sender = ret * vec[index];
				ops(cnt, sender, index + 1);
			}
			else if (i == 3){
				sender = ret / vec[index];
				ops(cnt, sender, index + 1);
			}
			op[i]++;
		}
	}
	return (0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt, num;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	ret = vec[0];
	for(int i = 0; i < 4; i++){
		cin >> op[i];
	}
	ops(cnt, ret, 1);
	cout << maxi << "\n" << mini;
}
