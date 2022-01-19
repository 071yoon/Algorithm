#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool	visited[101] = {0};
int 	ladder[101] = {0};
int 	snake[101] = {0};

queue <pair <int, int> > que;
int BFS(){
	que.push(make_pair(1, 0));
	int now = 1;
	int cnt = 0;
	while(1){
		now = que.front().first;
		cnt = que.front().second;
		if (now == 100)
			return (cnt);
		que.pop();
		for(int i = 1; i <= 6; i++){
			if (now + i <= 100 && !visited[now + i]){
				visited[now + i] = 1;
				if (ladder[now + i]){
					if (!visited[ladder[now + i]]){
						visited[ladder[now + i]] = 1;;
						que.push(make_pair(ladder[now + i], cnt + 1));
					}
				}
				else if (snake[now + i]){
					if (!visited[snake[now + i]]){
						visited[snake[now + i]] = 1;
						que.push(make_pair(snake[now + i], cnt + 1));
					}
				}
				else
					que.push(make_pair(now + i, cnt + 1));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int ladder_cnt, snake_cnt, num1, num2;
	cin >> ladder_cnt >> snake_cnt;
	while(ladder_cnt--){
		cin >> num1 >> num2;
		ladder[num1] = num2;
	}
	while (snake_cnt--){
		cin >> num1 >> num2;
		snake[num1] = num2;
	}
	cout << BFS() << "\n";
}