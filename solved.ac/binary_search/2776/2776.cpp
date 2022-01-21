#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int loop, cnt1, cnt2, num;
	cin >> loop;
	while(loop--){
		cin >> cnt1;
		vector <int> note1;
		for(int i = 0; i < cnt1; i++){
			cin >> num;
			note1.push_back(num);
		}
		sort(note1.begin(), note1.end());
		cin >> cnt2;
		for(int i = 0; i < cnt2; i++){
			cin >> num;
			cout << binary_search(note1.begin(), note1.end(), num) << "\n";
		}
	}
}