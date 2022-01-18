#include <stdio.h>
#include <algorithm>

int main(){
	int cnt, num, sum, cnt2;
	int org[100] = {0};
	int arr[161701] = {0};

	scanf("%d %d", &cnt, &num);
	arr[161700] = num;
	for (int i = 0; i < cnt; i++){
		scanf("%d", &org[i]);
	}
	cnt2 = 0;
	for(int i = 0; i < cnt - 2; i++){
		for(int j = i + 1; j < cnt-1; j++){
			for(int k = j + 1; k < cnt; k++){
				sum = 0;
				sum = org[i] + org[j] + org[k];
				if (sum == num){
					printf("%d", num);
					return (0);
				}
				else{
					arr[cnt2++] = sum;
				}
			}
		}
	}
	std::sort(arr, arr + 161701);
	int counter = 0;
	while (arr[counter] != num)
		counter++;
	printf("%d", arr[counter - 1]);
}