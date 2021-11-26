#include <stdio.h>

int checker(char *arr){
	int i = 0;

	while (arr[++i] != '\0'){
		int j = -1;
		if (arr[i] == arr[i - 1])
			continue ;
		while (++j < i){
			if (arr[j] == arr[i])
				return (0);
		}
	}
	return (1);
}

int main(){
	int cnt, loop;
	char arr[100] = {0};

	scanf("%d", &loop);
	cnt = 0;
	for (int i = 0; i < loop; i++){
		scanf("%s", arr);
		if (checker(arr))
			cnt++;
	}
	printf("%d", cnt);
}