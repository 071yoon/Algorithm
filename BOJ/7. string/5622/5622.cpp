#include <stdio.h>

int main(){
	char dial[16] = {0};
	int i, time;

	i = 0;
	time = 0;
	scanf("%s", dial);
	while (dial[i] != '\0'){
		if (dial[i] >= 'A' && dial[i] <= 'O'){
			time += ((dial[i] - 65) / 3) + 3;
		}
		else if (dial[i] >= 'P' && dial[i] <= 'S')
			time += 8;
		else if (dial[i] >= 'T' && dial[i] <= 'V')
			time += 9;
		else
			time += 10;
		i++;
	}
	printf("%d", time);
}