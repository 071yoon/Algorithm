#include <iostream>

using namespace std;

int blue = 0;
int white = 0;
int arr[128][128];

int check(int x, int y, int limit){
	int tmp = arr[x][y];
	for(int i = x; i < x + limit; i++){
		for(int j = y; j < y + limit; j++){
			if (arr[i][j] != tmp){
				return (0);
			}
		}
	}
	if (tmp == 1) blue++;
	else white++;
	return (1);
}

int solve(int x, int y, int limit){
	if (limit == 1){//sz == 1
		if (arr[x][y] == 1) blue++;
		else white++;
		return 0;
	}
	else if (check(x, y, limit)){
		return 0;
	}
	else{
		solve(x, y, limit / 2);//1
		solve(x + limit / 2, y, limit / 2);//2
		solve(x + limit / 2, y + limit / 2, limit / 2);//3
		solve(x, y + limit / 2, limit / 2);//4
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int sz;
	cin >> sz;
	for(int i = 0; i < sz; i++){
		for (int j = 0; j < sz; j++){
			cin >> arr[i][j];
		}
	}
	solve(0, 0, sz);
	cout << white << "\n" << blue;
}