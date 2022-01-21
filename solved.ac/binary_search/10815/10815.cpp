#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector <int> cards;
	vector <int> targets;
	int N, M, num;
	cin >> N;
	while(N--){
		cin >> num;
		cards.push_back(num);
	}
	sort(cards.begin(), cards.end());
	cin >> M;
	while(M--){
		cin >> num;
		cout << binary_search(cards.begin(), cards.end(), num) << " ";
	}
}