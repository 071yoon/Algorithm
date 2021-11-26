#include <stdio.h>

int main(){
	char c[1000000] = {0};
	int cnt = 1;
	int i = 0;

	scanf("%[^\n]", c);
	if (c[i] == ' ')
		i++;
	while (c[i] != '\0'){
		if (c[i] == ' '){
			cnt++;
		}
		i++;
	}
	if (c[i - 1] == ' ')
		cnt--;
	printf("%d", cnt);
}