#include <iostream>
#include <string>

using namespace std;
int arr[64][64];

int check(int x, int y, int limit){
	int tmp = arr[x][y];
	for(int i = x; i < x + limit; i++){
		for(int j = y; j < y + limit; j++){
			if (tmp != arr[i][j]){
				return (0);
			}
		}
	}
	cout << tmp;
	return (1);
}

int division(int x, int y, int limit){
	if (check(x, y, limit) == 1){
		return (0);
	}
	else{
		cout << "(";
		division(x, y, limit / 2);
		division(x, y + limit / 2, limit / 2);
		division(x + limit / 2, y, limit / 2);
		division(x + limit / 2, y + limit / 2, limit / 2);
		cout << ")";
	}
	return (1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int cnt;
	string str;

	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> str;
		for(int j = 0; j < cnt; j++)
			arr[i][j] = str[j] - '0';
	}
	division(0, 0, cnt);
}