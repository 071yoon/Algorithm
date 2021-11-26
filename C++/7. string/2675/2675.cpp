#include <stdio.h>

int main(){
	int cnt, cnt2, k;
	char buf[20];

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d", &cnt2);
		scanf("%s", buf);
		k = 0;
		while (buf[k] != '\0'){
			for (int j = 0; j < cnt2; j++){
				printf("%c", buf[k]);
			}
			k++;
		}
		printf("\n");
	}
}