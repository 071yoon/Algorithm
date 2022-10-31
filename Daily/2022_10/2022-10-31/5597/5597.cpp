#include <iostream>
using namespace std;

int nums[31] = {0};

int main() {
	nums[0] = 1;
	for(int i = 0; i < 28; i++){
		int num;
		cin >> num;
		nums[num] = 1;
	}
	for(int i = 0; i < 31; i++){
		if(nums[i] == 0){
			cout << i << "\n";
		}
	}
}