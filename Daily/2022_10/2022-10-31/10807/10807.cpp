#include <iostream>
using namespace std;

int nums[101] = {0};

int main(){
	int cnt;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		int num;
		cin >> num;
		nums[i] = num;
	}
	int target;
	cin >> target;
	int ans = 0;
	for(int i = 0; i < cnt; i++){
		if(nums[i] == target){
			ans++;
		}
	}
	cout << ans << "\n";
}
