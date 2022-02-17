#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int from_up[500001] = {0};
int from_down[500001] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int length, height, num;
	vector <int> vec;
	cin >> length >> height;
	for(int i = 0; i < length; i++){
		cin >> num;
		if (i % 2 == 0){
			from_down[num]++;
		}
		else
			from_up[num]++;
	}
	for(int i = height - 1; i >= 1; i--){
		from_down[i] += from_down[i + 1];
		from_up[i] += from_up[i + 1];
	}
	for(int i = 1; i <= height; i++)
		vec.push_back(from_down[i] + from_up[height - i + 1]);
	sort(vec.begin(), vec.end());
	int ret = 1;
	for(int i = 1; i < vec.size(); i++){
		if (vec[i] == vec[0]){
			ret++;
		}
		else
			break ;
	}
	cout << vec[0] << " " << ret << "\n";
}