#include <iostream>

using namespace std;

int cnt, M, N, K, ret;
int arr[52][52] = {0};

void clear_area(int y, int x){
	if (arr[y + 1][x]){
		arr[y + 1][x] = 0;
		clear_area(y + 1, x);
	}
	if (arr[y - 1][x]){
		arr[y - 1][x] = 0;
		clear_area(y - 1, x);
	}
	if (arr[y][x + 1]){
		arr[y][x + 1] = 0;
		clear_area(y, x + 1);
	}
	if (arr[y][x - 1]){
		arr[y][x - 1] = 0;
		clear_area(y, x - 1);
	}
}

void DFS(){
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			if (arr[y][x]){
				arr[y][x] = 0;
				ret++;
				clear_area(y, x);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> cnt;
	int num1, num2;
	for(int i = 0; i < cnt; i++){
		cin >> M >> N >> K;
		for(int i = 1; i <= N; i++){
			for(int i = 1; i <= M; i++){
				arr[N][M] = 0;
			}
		}
		ret = 0;
		for(int i = 0; i < K; i++){
			cin >> num1 >> num2;
			arr[num2 + 1][num1 + 1] = 1;
		}
		DFS();
		cout << ret << "\n";
	}
}