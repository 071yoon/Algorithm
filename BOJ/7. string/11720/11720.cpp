#include <stdio.h>
#include <stdlib.h>

int main(){
	char c[100] = {0};
	int cnt, ret, i;

	scanf("%d", &cnt);
	scanf("%s", c);
	ret = 0;
	i = 0;
	while (c[i] != '\0'){
		ret += c[i++] - 48;
	}
	printf("%d", ret);
}