#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	multiset <int> cards;
	int cnt, num;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> num;
		cards.insert(num);
	}
	int ret = 0;
	while (cards.size() > 1){
		int front = *cards.begin();
		cards.erase(cards.begin());
		int two = *cards.begin();
		cards.erase(cards.begin());
		ret += front + two;
		cards.insert(front + two);
	}
	cout << ret << "\n";
	
}