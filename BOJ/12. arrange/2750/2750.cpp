#include <stdio.h>
#include <algorithm>

int main(){
	int cnt;
	int *arr;

	scanf("%d", &cnt);
	arr = new int[cnt];
	for (int i = 0; i < cnt; i++)
		scanf("%d", &arr[i]);
	std::sort(arr, arr + cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d\n", arr[i]);
}