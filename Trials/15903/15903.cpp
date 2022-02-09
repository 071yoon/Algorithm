#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	priority_queue <long long, vector<long long>, greater<long long> > pq;
	int n, m, num;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> num;
		pq.push(num);
	}
	for(int i = 0; i < m; i++){
		long long ft = pq.top();
		pq.pop();
		long long sc = pq.top();
		pq.pop();
		pq.push(ft + sc);
		pq.push(ft + sc);
	}
	long long ret = 0;
	while (!pq.empty()){
		ret += pq.top();
		pq.pop();
	}
	cout << ret << "\n";
}