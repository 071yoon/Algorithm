#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue <int> first_que;
	int cnt, num;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		first_que.push(num);
	}
	
	
}