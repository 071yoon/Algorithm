#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N, M, max_val = 0;
vector <int> boxes;
vector <int> cranes;

bool compare(int a, int b){
	return a > b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int tmp;
	for(int i = 0; i < N; i++){
		cin >> tmp;
		cranes.push_back(tmp);
		max_val = max(tmp, max_val);
	}
	sort(cranes.begin(), cranes.end(), compare);
	cin >> M;
	for(int i = 0; i < M; i++){
		cin >> tmp;
		boxes.push_back(tmp);
	}
	sort(boxes.begin(), boxes.end(), compare);
	if (boxes[0] > max_val){
		cout << "-1\n";
		return (0);
	}
	int ret = 0;
	while (1){
		ret++;
		for(int i = 0; i < cranes.size(); i++){
			for(int j = 0; j < boxes.size(); j++){
				if (cranes[i] >= boxes[j]){
					boxes.erase(boxes.begin() + j);
					break;
				}
			}
		}
		if (boxes.empty()){
			break;
		}
	}
	cout << ret << "\n";	

}
//15mins