#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A[101][101] = {0};
	int B[101][101] = {0};
	int ret[101][101] = {0};
	int N,M,K;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			cin >> A[i][j];
	}
	cin >> M >> K;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < K; j++)
			cin >> B[i][j];
	}

	for(int x = 0; x < N; x++){
		for(int y = 0; y < K; y++){
			for(int i = 0; i < M; i++){
				ret[x][y] += A[x][i] * B[i][y];
			}
			cout << ret[x][y] << " ";
		}
		cout << "\n";
	}
}