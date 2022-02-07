#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

	queue <int> que;
	for(int i = 0; i < progresses.size(); i++){
		if (((100 - progresses[i]) % speeds[i]) == 0){
			que.push((100 - progresses[i]) / speeds[i]);
		}
		else{
			que.push(((100 - progresses[i]) / speeds[i]) + 1);
		}
	}
	while(!que.empty()){
		int cnt = 1;
		int tmp = que.front();
		que.pop();
		while(!que.empty()){
			if (que.front() <= tmp){
				que.pop();
				cnt++;
			}
			else
				break ;
		}
		answer.push_back(cnt);
	}
    return answer;
}