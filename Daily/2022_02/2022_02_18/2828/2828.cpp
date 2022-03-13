#include <vector>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int screen, basket, cnt;
	cin >> screen >> basket >> cnt;
	vector <int> vec;
	for(int i = 0; i < cnt; i++){
		int num;
		cin >> num;
		vec.push_back(num);
	}
	int start = 1; int ender = basket;
	int ret = 0;
	for(int i = 0; i < vec.size(); i++){
		if (vec[i] > ender){
			int dif = vec[i] - ender;
			ret += dif;
			start += dif;
			ender += dif;
		}
		else if (vec[i] < start){
			int dif = start - vec[i];
			ret += dif;
			start -= dif;
			ender -= dif;
		}
	}
	cout << ret << "\n";
}