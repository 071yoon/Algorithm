#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt;
	float tp_len, num;
	cin >> cnt >> tp_len;
	vector <float> holes;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		holes.push_back(num);
	}
	sort(holes.begin(), holes.end());
	float tp_ptr = holes[0] - 0.5;
	int ret = 0;
	int index = 0;
	for(int i = 0; i < cnt; i++){
		if (tp_ptr <= holes[i] - 0.5){
			tp_ptr = holes[i] - 0.5 + tp_len;
			ret++;
		}
		else{
			if (tp_ptr >= holes[i] + 0.5)
				continue;
			else{
				tp_ptr += tp_len;
				ret++;
			}
		}
	}
	cout << ret << "\n";
}