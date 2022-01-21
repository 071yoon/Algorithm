#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector <int> ret;
	vector <int>::iterator iter;
	int cnt, num;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		iter = lower_bound(ret.begin(), ret.end(), num);
		if (iter == ret.end()){
			ret.push_back(num);
		}
		else{
			*iter = num;
		}
	}
	cout << ret.size() << "\n";
}