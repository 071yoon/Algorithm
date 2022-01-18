#include <stdio.h>

int main(){
	char alphabet[26];
	char c[100] = {0};
	int i;
	
	scanf("%s", c);
	for (int k = 0; k < 26; k++){
		i = 0;
		while (c[i] != '\0'){
			if (c[i] == (char)(k + 97)){
				printf("%d ", i);
				break;
			}
			i++;
		}
		if (c[i] == '\0')
			printf("-1 ");
	}
}