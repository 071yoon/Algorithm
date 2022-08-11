#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const int& a, const int& b){
	return a > b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int cnt, prize_cnt;
	cin >> cnt >> prize_cnt;
	vector <int> people;
	for(int i = 0; i < cnt; i++){
		int score;
		cin >> score;
		people.push_back(score);
	}
	sort(people.begin(), people.end(), cmp);
	cout << people[prize_cnt - 1] << "\n";
}