#include <iostream>
using namespace std;

int N;
int arr[101][101] = {0};
long long dynamic[101][101] = {0};

void dp(int y, int x){
	if (arr[y][x] == 0)
		return ;
	else{
		if (y + arr[y][x] <= N && x + arr[y][x] <= N){
			if (!dynamic[y + arr[y][x]][x])
				dp(y + arr[y][x], x);
			if (!dynamic[y][x + arr[y][x]])
				dp(y, x + arr[y][x]);
			dynamic[y][x] = dynamic[y + arr[y][x]][x] + dynamic[y][x + arr[y][x]];
		}
		else if (y + arr[y][x] <= N && x + arr[y][x] > N){
			if (!dynamic[y + arr[y][x]][x])
				dp(y + arr[y][x], x);
			dynamic[y][x] = dynamic[y + arr[y][x]][x];
		}
		else if (y + arr[y][x] > N && x + arr[y][x] <= N){
			if (!dynamic[y][x + arr[y][x]])
				dp(y, x + arr[y][x]);
			dynamic[y][x] = dynamic[y][x + arr[y][x]];
		}
		else
			return ;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> arr[i][j];
		}
	}
	dynamic[N][N] = 1;
	dp(1, 1);
	cout << dynamic[1][1] << "\n";
}