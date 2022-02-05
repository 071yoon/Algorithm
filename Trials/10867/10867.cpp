#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cnt, num;
	cin >> cnt;
	vector <int> vec;
	map <int, int> mapper;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		mapper[num]++;
	}
	for(auto it = mapper.begin(); it != mapper.end(); it++)
		cout << it->first << " ";
	cout << "\n";
}