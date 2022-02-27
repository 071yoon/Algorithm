#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	vector <int> vec;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	int ret = 0;
	for(int i = 0; i < cnt; i++){
		int start = 0; int end = cnt - 1;
		while(start < end){
			if (start == i){
				start++;
				continue ;
			}
			if (end == i){
				end--;
				continue;
			}
			if (vec[start] + vec[end] == vec[i]){
				ret++;
				break ;
			}
			else if (vec[start] + vec[end] < vec[i]){
				start++;
			}
			else{
				end--;
			}
		}
	}
	cout << ret << "\n";
}
//8mins 12sec