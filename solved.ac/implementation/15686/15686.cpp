#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cnt, chicken_cnt, tmp;
	vector <int> distance[2500];
	vector <pair<int, int> > house;
	vector <pair<int, int> > chicken;
	cin >> cnt >> chicken_cnt;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < cnt; j++){
			cin >> tmp;
			if (tmp == 1){
				house.push_back(make_pair(i, j));
			}
			else if (tmp == 2){
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	for(int i = 0; i < house.size(); i++){
		for(int j = 0; j < chicken.size(); j++){
			distance[i].push_back(abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
		}
	}
	vector <int> s;
	vector <int> tmp_vec;
	for(int i = 0; i < chicken.size(); i++){
		s.push_back(i);
		if (chicken_cnt-- > 0)
			tmp_vec.push_back(1);
		else
			tmp_vec.push_back(0);
	}
	int min_ret = INT_MAX;
	do {
		int sum = 0;
		for(int loop = 0; loop < house.size(); loop++){
			int min_tmp = INT_MAX;
			for (int i = 0; i < s.size(); i++){
				if (tmp_vec[i] == 1){
					min_tmp = min(min_tmp, distance[loop][i]);
				}
			}
			sum += min_tmp;
		}
		min_ret = min(min_ret, sum);
	}while(prev_permutation(tmp_vec.begin(), tmp_vec.end()));
	cout << min_ret << "\n";
}