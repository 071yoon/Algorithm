#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	cin >> cnt;
	while (cnt != 0){
		vector <int> vec;
		for(int i = 0; i < cnt; i++){
			cin >> num;
			vec.push_back(num);
		}
		vector <int> temp;
		for(int i = 0; i < 6; i++)
			temp.push_back(1);
		for(int i = 6; i < cnt; i++){
			temp.push_back(0);
		}
		sort(vec.begin(), vec.end());
		do {
        for (int i = 0; i < vec.size(); ++i) {
            if (temp[i] == 1)
                cout << vec[i] << ' ';
        }
        cout << "\n";
    	} while (prev_permutation(temp.begin(), temp.end()));
		cout << "\n";
		cin >> cnt;
	}
}