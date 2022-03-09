#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--){
		int cnt, num;
		cin >> cnt;
		vector <int> vec;
		vector <int> ans;
		for(int i = 1; i <= cnt; i++){
			cin >> num;
			int iter = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
			vec.insert(vec.begin() + iter, num);
			if (i % 2){
				ans.push_back(vec[i / 2]);
			}
		}
		cout << ans.size() << "\n";
		for(int i = 0; i < ans.size(); i++){
			if ((i + 1) % 10 == 0){
				cout << ans[i] << "\n";
			}
			else{
				cout << ans[i] << " ";
			}
		}
		cout << "\n";
	}
}