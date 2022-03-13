#include <iostream>
#include <vector>
using namespace std;

vector <int> garo;
int len, cnt;

bool test(int mid){
	int x = garo[0] - mid;
	int y = garo[0] + mid;
	if (x > 0)
		return false;
	for(int i = 1; i < garo.size(); i++){
		if (y < garo[i] - mid)
			return false;
		y = garo[i] + mid;
	}
	if (y < len)
		return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> len >> cnt;
	for(int i = 0; i < cnt; i++){
		int num;
		cin >> num;
		garo.push_back(num);
	}
	int starter = 1; int ender = 987654321;
	int ret = 0;
	while (starter <= ender){
		int mid = (starter + ender) / 2;
		if (test(mid)){
			ret = mid;
			ender = mid - 1;
		}
		else
			starter = mid + 1;
	}
	cout << ret << "\n";
}
/*
9:40
*/