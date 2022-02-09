#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int A[50][50] = {0};
int B[50][50] = {0};

void swap(int x, int y){
	for(int i = x; i <= x + 2; i++){
		for(int j = y; j <= y + 2; j++){
			A[i][j] = 1 - A[i][j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	string str;
	cin >> N >> M;

	for (int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < M; j++)
			A[i][j] = str[j] - '0';
	}
	for (int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < M; j++)
			B[i][j] = str[j] - '0';
	}
	int cnt = 0;
	for(int i = 0; i < N - 2; i++){
		for(int j = 0; j < M - 2; j++){
			if (A[i][j] != B[i][j]){
				swap(i, j);
				cnt++;
			}
		}
	}
	for(int i = 0; i < N * M; i++){
		if (A[i / M][i % M] != B[i / M][i % M]){
			cout << "-1\n";
			return (0);
		}
	}
	cout << cnt << "\n";
}