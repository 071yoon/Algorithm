#include <iostream>

using namespace std;

int arr[15] = {0};
int right_diag[29] = {0};
int left_diag[29] = {0};
int num;
int total;

void nqueen(int y){
	if (y == num){
		total++;
	}
	else{
		for(int x = 0; x < num; x++){
			if (arr[x] == 0 && right_diag[(num - 1) - y + x] == 0 &&
			left_diag[2 * (num - 1) - x - y] == 0){
				arr[x] = 1;
				right_diag[(num - 1) - y + x] = 1;
				left_diag[2 * (num - 1) - x - y] = 1;
				nqueen(y + 1);
				arr[x] = 0;
				right_diag[(num - 1) - y + x] = 0;
				left_diag[2 * (num - 1) - x - y] = 0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	total = 0;
	nqueen(0);
	cout << total;
}