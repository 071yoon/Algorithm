#include <stdio.h>
#include <algorithm>

int main(){
	int cnt;
	int num;
	int arr[10001] = {0};

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d", &num);
		arr[num]++;
	}
	for (int i = 1; i < 10001; i++){
		for(int j = 0; j < arr[i]; j++){
			printf("%d\n", i);
		}
	}
}