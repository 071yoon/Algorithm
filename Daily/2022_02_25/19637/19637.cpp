#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, trial, num;
	vector <pair<int, string> > vec;
	string str;
	cin >> cnt >> trial;
	for(int i = 0; i < cnt; i++){
		cin >> str >> num;
		vec.push_back(make_pair(num, str));
	}
	for(int i = 0; i < trial; i++){
		cin >> num;
		int starter = 0, ender = cnt - 1, ret = 0;
		while (starter <= ender){
			int mid = (starter + ender) / 2;
			if (vec[mid].first >= num){
				ret = mid;
				ender = mid - 1;
			}
			else{
				starter = mid + 1;
			}
		}
		cout << vec[ret].second << "\n";
	}
}
//13mins 40sec