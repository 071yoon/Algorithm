#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int joka, cnt, max_len = 0;
vector <int> gaja;

bool test(int mid){
	int ret = 0;
	for(int i = 0; i < cnt; i++){
		ret += gaja[i] / mid;
	}
	if (ret >= joka) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> joka >> cnt;
	for(int i = 0; i < cnt; i++){
		int num;
		cin >> num;
		gaja.push_back(num);
		max_len = max(max_len, num);
	}
	int starter = 1, ender = max_len;
	int final = 0;
	while (starter <= ender){
		int mid = (starter + ender) / 2;
		if (test(mid)){
			final = max(final, mid);
			starter = mid + 1;
		}
		else
			ender = mid - 1;
	}
	cout << final << "\n";
}
//7mins 13sec