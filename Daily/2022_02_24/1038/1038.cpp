#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool nums[10] = {0};
int cnt = 0, ret;
vector <long long> ans;

bool down(string str){
	for(int i = 1; i < str.length(); i++){
		if (str[i] >= str[i - 1]){
			return false;
		}
	}
	return true;
}

void back_tracking(string tmp){
	if (tmp.length() >= 1){
		if (down(tmp)){
			ans.push_back(stoull(tmp));
		}
	}
	for(int i = 0; i < 10; i++){
		if (nums[i] == 0){
			nums[i] = 1;
			char c = i + '0';
			tmp += c;
			back_tracking(tmp);
			tmp.pop_back();
			nums[i] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string tmp = "";
	cin >> ret;
	back_tracking(tmp);
	sort(ans.begin(), ans.end());
	if (ret >= ans.size()){
		cout << "-1\n";
		return (0);
	}
	cout << ans[ret] << "\n";
}
/*
1 - 1
2 - 2
3 - 3
4 - 4
5 - 5
6 - 6
7 - 7
8 - 8
9 - 9
10-10
20-11
21-12
30-13
31-14
32-15
40-16
41-17
42-18



*/