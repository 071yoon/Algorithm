#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, mon1, mon2, day1, day2;
	vector <pair<int, int> > flowers;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> mon1 >> day1 >> mon2 >> day2;
		int tmp1 = 0, tmp2 = 0;
		for(int i = 0; i < mon1 - 1; i++){
			tmp1 += month[i];
		}
		for(int j = 0; j < mon2 - 1; j++){
			tmp2 += month[j];
		}
		flowers.push_back(make_pair(tmp1 + day1, tmp2 + day2));
	}
	//3,1 -> 31 + 28 + 1 = 60
	int end_day = 0;
	for(int i = 0; i < 10; i++){
		end_day += month[i];
	}
	end_day += 30;
	sort(flowers.begin(), flowers.end());
	int ender = 60; int ret = 0;
	while (ender <= end_day){
		int strt = ender;
		ender = 0;
	//	cout << strt << "\n";
		for(int i = 0; i < cnt; i++){
			if (flowers[i].first <= strt && flowers[i].second > strt){
				ender = max(flowers[i].second, ender);
			}
		}
	//	cout << ender << "\n";
		if (ender == 0){
			cout << "0\n";
			return (0);
		}
		ret++;
	}
	cout << ret << "\n";
}
/*
3월 1일전에 필수 있는거 따로 모아서 제일 큰 친구 저장 -> 11월 30일 되는지 확인
그 친구 기준 더 작은 친구중에 제일 큰 친구 저장 -> 확인
반복
33mins 35sec
*/