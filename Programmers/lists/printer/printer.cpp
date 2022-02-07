#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;

	queue <pair<int, int> > que;
	priority_queue <int> pq;
	for(int i = 0; i < priorities.size(); i++){
		que.push(make_pair(priorities[i], i));
		pq.push(priorities[i]);
	}
	while (1){
		if (que.front().first == pq.top()){
			if (location == que.front().second){
				return answer;
			}
			else{
				answer++;
				que.pop();
				pq.pop();
			}
		}
		else{
			int ft = que.front().first;
			int sd = que.front().second;
			que.pop();
			que.push(make_pair(ft, sd));
		}
	}
}