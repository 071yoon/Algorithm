#include <stdio.h>

int main(){
	char arr[102] = {0};
	int i, j, cnt;

	scanf("%s", arr);
	i = -1;
	cnt = 0;
	while (arr[++i] != '\0'){
		if ((arr[i] == 'c' || arr[i] == 's' || arr[i] == 'z') && (arr[i + 1] == '='))
			i++;
		else if ((arr[i] == 'c' || arr[i] == 'd') && (arr[i + 1] == '-'))
			i++;
		else if ((arr[i] == 'l' || arr[i] == 'n') && (arr[i + 1] == 'j'))
			i++;
		else if (arr[i] == 'd' && arr[i + 1] == 'z' && arr[i+2] == '=')
			i += 2;
	cnt++;
	}
	printf("%d", cnt);
}