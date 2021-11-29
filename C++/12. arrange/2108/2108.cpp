#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

void print_mode(int *arr, int cnt){
	int cntr1, max, flag, tmp, ans;

	max = 0;
	flag = 0;
	for (int i = 0; i < cnt; i++){
		cntr1 = 1;
		tmp = i;
		while (arr[i] == arr[i + 1]){
			cntr1++;
			i++;
		}
		i = tmp;
		if (max == cntr1 && flag != 1){
			ans = arr[i];
			flag++;
		}
		else if (max < cntr1){
			max = cntr1;
			ans = arr[i];
			flag = 0;
		}
	}
	printf("%d\n", ans);
}

int main(){
	int cnt, num;
	int arr[8001] = {0};

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d", &num);
		arr[num]++;
	}
//	std::sort(arr, arr + cnt);
	int sum = 0;
	for (int i = 0; i < 8001; i++){
		sum += arr[i];
	}
	printf("\n%.f\n", round((double)sum/(double)cnt));
	printf("%d\n", arr[cnt / 2]);
//	print_mode(arr, cnt);
//	printf("%d", arr[cnt-1] - arr[0]);
	delete[] arr;
}