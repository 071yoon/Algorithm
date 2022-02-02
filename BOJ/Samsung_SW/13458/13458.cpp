#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector <int> places;
	long long place_cnt, tmp_people, total_ins, sub_ins;

	cin >> place_cnt;
	for(int i = 0; i < place_cnt; i++){
		cin >> tmp_people;
		places.push_back(tmp_people);
	}
	cin >> total_ins >> sub_ins;

	long long sum = 0;
	for(int i = 0; i < place_cnt; i++){
		places[i] -= total_ins;
		sum += 1;
		if (places[i] <= 0)
			continue;
		if (places[i] % sub_ins == 0){
			sum += places[i] / sub_ins;
		}
		else
			sum += (places[i] / sub_ins) + 1;
	}
	cout << sum << "\n";
}