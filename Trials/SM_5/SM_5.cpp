#include <iostream>
#include <map>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int sz;
	cin >> sz;
	map <int, int> maxy;
	int score, times, times2, ret = 0;
	for(int i = 0; i < sz * sz; i++){
		cin >> score >> times;
		for(int j = 0; j < times; j++){
			cin >> times2;
			if (maxy[times2]){
				ret += score - maxy[times2];
			}
			else{
				ret += score;
			}
			maxy[times2] = score;
		}
	}
	cout << ret << "\n";
}