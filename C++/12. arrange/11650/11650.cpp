/*
//First Try
#include <stdio.h>
#include <algorithm>

void switcher(int *x_arr, int *y_arr, int switcher, int switching){
	int tmpx, tmpy;

	tmpx = x_arr[switcher];
	tmpy = y_arr[switcher];
	x_arr[switcher] = x_arr[switching];
	y_arr[switcher] = y_arr[switching];
	x_arr[switching] = tmpx;
	y_arr[switching] = tmpy;
}

void sort(int *x_arr, int *y_arr, int cnt){
	for (int i = 0; i < cnt - 1; i++){
		for (int j = i + 1; j < cnt; j++){
			if (x_arr[j] < x_arr[i])
				switcher(x_arr, y_arr, j, i);
			else if (x_arr[j] == x_arr[i]){
				if (y_arr[j] < y_arr[i]){
					switcher(x_arr, y_arr, j, i);
				}
			}
		}
	}
}

int main(){
	int *x_arr;
	int *y_arr;
	int cnt;

	scanf("%d", &cnt);
	x_arr = new int[cnt];
	y_arr = new int[cnt];
	for (int i = 0; i < cnt; i++){
		scanf("%d %d", &x_arr[i], &y_arr[i]);
	}
	sort(x_arr, y_arr, cnt);
	for (int i = 0; i < cnt; i++){
		printf("%d %d\n", x_arr[i], y_arr[i]);
	}
}

*/

//Second Try
#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<std::pair<int, int> > v;

int main(){
	int cnt, tmpx, tmpy;

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d %d", &tmpx, &tmpy);
		v.push_back(std::pair<int, int>(tmpx, tmpy));
	}
	std::sort(v.begin(), v.end());
	for (int i = 0; i < cnt; i++){
		printf("%d %d\n", v[i].first, v[i].second);
	}
}