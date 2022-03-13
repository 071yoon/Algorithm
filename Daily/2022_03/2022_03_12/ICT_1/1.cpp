#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int money, vector<int> costs) {
    int answer = 0;
	vector <pair<int, int> > cost;
	for(int i = 0; i < 6; i++){
		int num = 0;
		if (i == 0){
			costs[i] *= 500;
			num = 1;
		}
		else if (i == 1){
			costs[i] *= 100;
			num = 5;
		}
		else if (i == 2){
			costs[i] *= 50;
			num = 10;
		}
		else if (i == 3){
			costs[i] *= 10;
			num = 50;
		} 
		else if (i == 4){
			costs[i] *= 5;
			num = 100;
		} 
		else num = 500;
		cost.push_back(make_pair(costs[i], num));
	}
	sort(cost.begin(), cost.end());
	for(int i = 0; i < 6; i++){
		cout << cost[i].first << ":" << cost[i].second << "\n";
	}
	for(int i = 0; i < 6; i++){
		int hana = (cost[i].first) / (500 / cost[i].second);
		cout << hana << "\n";
		int mon = (money / cost[i].second) * (hana);
		answer = answer + mon;
		money %= hana;
	}
    return answer;
}
