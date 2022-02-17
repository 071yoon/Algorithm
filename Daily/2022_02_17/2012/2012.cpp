#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	vector <int> grade;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		grade.push_back(num);
	}
	sort(grade.begin(), grade.end());
	long long tmp = 0;
	for(int i = 0; i < cnt; i++){
		tmp += abs((i + 1) - grade[i]);
	}
	cout << tmp << "\n";
}