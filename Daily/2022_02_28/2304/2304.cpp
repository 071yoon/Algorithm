#include <algorithm>
#include <iostream>
using namespace std;

int blocks[1002][3] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num1, num2;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num1 >> num2;
		blocks[num1][0] = num2;
	}
	for(int i = 1; i <= 1000; i++){
		blocks[i][1] = max(blocks[i][0], blocks[i - 1][1]);
	}
	for(int i = 1000; i >= 1; i--){
		blocks[i][2] = max(blocks[i][0], blocks[i + 1][2]);
	}
	int ret = 0;
	for(int i = 1; i <= 1000; i++){
		ret += min(blocks[i][1], blocks[i][2]);
	}
	cout << ret << "\n";
}