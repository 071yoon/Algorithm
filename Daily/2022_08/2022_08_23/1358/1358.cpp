#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int w, h, x, y, cnt;
	int ret = 0;
	cin >> w >> h >> x >> y >> cnt;
	for(int i = 0; i < cnt; i++){
		int num1, num2;
		cin >> num1 >> num2;
		if (num1 >= x && num1 <= x + w && num2 >= y && num2 <= y + h){
			ret++;
		} else if ((num1 - x) * (num1 - x) + (num2 - y - (h / 2)) * (num2 - y - (h / 2)) <= h * h / 4){
			ret++;
		} else if ((num1 - x - w) * (num1 - x - w) + (num2 - y - (h / 2)) * (num2 - y - (h / 2)) <= h * h / 4){
			ret++;
		}
	}
	cout << ret << "\n";

}

// inputs
// W H X Y P
// 20 10 5 0 3
// 15 5
// 1 5
// 1 1