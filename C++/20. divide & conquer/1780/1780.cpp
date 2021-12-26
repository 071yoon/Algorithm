#include <iostream>

using namespace std;
int arr[2187][2187];
int result[3] = {0};
int cnt;

int check(int x, int y, int limit){
	if (limit == 1){
		return (1);
	}
	else{
		for(int i = x; i < x + limit; i++){
			for (int j = y; j < y + limit; j++){
				if (arr[x][y] != arr[i][j])
					return (0);
			}
		}
	}
	return (1);
}

void div(int x, int y, int limit){
	if (check(x, y, limit) == 1){
		if (arr[x][y] == 1)
			result[0]++;
		else if (arr[x][y] == -1)
			result[1]++;
		else
			result[2]++;
	}
	else{
		div(x, y, limit / 3);
		div(x + limit / 3, y, limit / 3);
		div(x + (2 * (limit / 3)), y, limit / 3);
		div(x, y + limit / 3, limit / 3);
		div(x + limit / 3, y + limit / 3, limit / 3);
		div(x + (2 * (limit / 3)), y + limit / 3, limit / 3);
		div(x, y + (2 * (limit / 3)), limit / 3);
		div(x + limit / 3, y + (2 * (limit / 3)), limit / 3);
		div(x + (2 * (limit / 3)), y + (2 * (limit / 3)), limit / 3);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		for (int j = 0; j < cnt; j++)
			cin >> arr[i][j];
	}
	div(0, 0, cnt);
	cout << result[1] << "\n" << result[2] << "\n" << result[0] << "\n";
}