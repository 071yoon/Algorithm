#include <iostream>
using namespace std;

int mapp[100] = {0};
bool visited[100] = {0};
int ret = 0, tmp = 0;

void solution(int me){
	visited[me] = 1;
	int next = me + mapp[me];
	if (visited[next]){
		ret = max(ret, tmp + 1);
		return ;
	}
	else{
		tmp++;
		solution(next);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> mapp[i];
	}
	for(int i = 0; i < 3; i++){
		memset(visited, 0, sizeof(visited));
		tmp = 1;
		solution(i);
	}
	cout << ret << "\n";
}