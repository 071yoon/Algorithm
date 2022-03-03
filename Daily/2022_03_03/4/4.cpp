#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int cnt;
int mapp[101] = {0};
bool visited[101] = {0};
int max_plates = 0;

void run_plate(int now, int ret){
	if (!visited[now + mapp[now]]){
		visited[now + mapp[now]] = 1;
		run_plate(now + mapp[now], ret + 1);
	}
	else{
		max_plates = max(max_plates, ret + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> cnt;
	for(int i = 1; i <= cnt; i++){
		cin >> mapp[i];
	}
	for(int i = 1; i <= 3; i++){
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		run_plate(i, 1);
	}
	cout << max_plates << "\n";
}
//10mins 42sec