#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int BFS(){

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long A, B;
	cin >> A >> B;
	queue <pair<long long, long long> > que;
	que.push(make_pair(A, 1));
	while (!que.empty()){
		long long num = que.front().first;
		long long cnt = que.front().second;
		que.pop();
		if (num == B){
			cout << cnt << "\n";
			return(0);
		}
		else if (num > B){
			continue ;
		}
		else{
			que.push(make_pair(num * 2 , cnt + 1));
			que.push(make_pair(num * 10 + 1, cnt + 1));
		}
	}
	cout << "-1\n";
}