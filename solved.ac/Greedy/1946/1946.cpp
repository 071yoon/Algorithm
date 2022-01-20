#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int cnt, loop, num1, num2;
	cin >> cnt;
	while(cnt--){
		cin >> loop;
		int org_loop = loop;
		vector <pair<int, int> > vec;
		while(loop--){
			cin >> num1 >> num2;
			vec.push_back(make_pair(num1, num2));
		}
		sort(vec.begin(), vec.end());
		int cnt = 1;
		int tmp = vec[0].second;
		for(int i = 1; i < org_loop; i++){
			if (vec[i].second < tmp){
				tmp = vec[i].second;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}