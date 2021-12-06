#include <stdio.h>
#include <algorithm>

int main(){
	long long num, org;
	int cnt;
	int *arr;

	scanf("%lld", &num);
	org = num;
	cnt = 0;
	while (num){
		num /= 10;
		cnt++;
	}
	arr = new int[cnt];
	int tmp = cnt;
	while (cnt){
		arr[cnt - 1] = (org % 10);
		org /= 10;
		cnt--;
	}
	std::sort(arr, arr + tmp);
	for (int i = 0; i < tmp; i++)
		printf("%d", arr[tmp - i - 1]);
}