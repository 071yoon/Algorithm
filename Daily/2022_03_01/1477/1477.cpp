#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, L, num;
	cin >> N >> M >> L;
	vector <int> huge;
	huge.push_back(L);
	huge.push_back(0);
	for(int i = 0; i < N; i++){
		cin >> num;
		huge.push_back(num);
	}
	sort(huge.begin(), huge.end());
	for(int i = 0; i < N; i++){
		int index = 1;
		int max_val = 0;
		for(int j = 1; j < huge.size(); j++){
			if (max_val < huge[j] - huge[j - 1]){
				index = j;
				max_val = huge[j] - huge[j - 1];
			}
		}
		//cout << index << "\n";
		huge.insert(huge.begin() + index, ((huge[index] + huge[index - 1]) / 2));
	}
	for(int i = 0; i < huge.size(); i++){
		cout << huge[i] << " ";
	}
	cout << "\n";
	int max_val = 0;
	for(int i = 1; i < huge.size(); i++){
		if (max_val < huge[i] - huge[i - 1]){
			max_val = huge[i] - huge[i - 1];
		}
	}
	cout << max_val << "\n";
}
/*
0 82 201 411 555 622 755 800
 82 119 210 144 67 133 45


*/