#include <stdio.h>

void print_max(int *arr){
	int max = 0;
	int tmp = 0;
	int cnt = 0;

	for (int i = 0; i < 26; i++){
		if (arr[i] >= max)
			max = arr[i];
	}
	for (int i = 0; i < 26; i++){
		if (max == arr[i]){
			tmp = i;
			cnt++;
		}
	}
	if (cnt == 1)
		printf("%c", (char)(tmp + 65));
	else
		printf("?");
}

int main(){
	char arr[1000000];
	int alph[26] = {0};

	scanf("%s", arr);
	int i = 0;
	while (arr[i] != '\0'){
		if (arr[i] >= 'A' && arr[i] <= 'Z'){
			alph[arr[i] - 65]++;
		}
		else if (arr[i] >= 'a' && arr[i] <= 'z'){
			alph[arr[i] -97]++;
		}
		i++;
	}
	print_max(alph);
}