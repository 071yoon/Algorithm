#include <string>
#include <vector>
#include <iostream>
using namespace std;

void back_tracking(int cnt, int size, int *ret, int value, vector<int> &numbers, int target){
	if (cnt == size){
        if (value == target){
            cout << "hello\n";
		    *ret += 1;
        }
		return ;
	}
	back_tracking(cnt + 1, size, ret, value + numbers[cnt], numbers, target);
	back_tracking(cnt + 1, size, ret, value - numbers[cnt], numbers, target);
}

int solution(vector<int> numbers, int target) {
	int sz = numbers.size();
	int ret = 0;
	back_tracking(0, sz, &ret, 0, numbers, target);
    return ret;
}