#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	string str;
	string ans;
	map <char, int> m;
	cin >> str;
	cin >> ans;

	for(int i = 0; i < str.size(); i++) {
		m[str[i]] = i;
	}
	int cur = 0;
	int press_cnt = 0;
	int left_cnt = 0;
	int right_cnt = 0;
	for(int i = 0; i < ans.size(); i++) {
		// check how many times to rotate
		int next = m[ans[i]];
		int tmp_left_cnt;
		int tmp_right_cnt;
		if(cur == next) {
			press_cnt++;
			continue;
		}
		// rotate left & right
		if(cur < next) {
			tmp_left_cnt = next - cur;
			tmp_right_cnt = str.size() - next + cur;
		} else {
			tmp_left_cnt = str.size() - cur + next;
			tmp_right_cnt = cur - next;
		}
		if(tmp_left_cnt <= tmp_right_cnt) {
			left_cnt += tmp_left_cnt;
		} else {
			right_cnt += tmp_right_cnt;
		}
		cur = next;
		press_cnt++;
	}
	cout << press_cnt + left_cnt + right_cnt << " " << left_cnt << " " << right_cnt << "\n";
	return 0;
}