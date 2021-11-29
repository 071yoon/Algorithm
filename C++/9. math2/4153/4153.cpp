#include <stdio.h>
#include <algorithm>

int main(){
	int length[3] = {1, 1, 1};
	int max, tmp1, tmp2;

	while (1){
		scanf("%d %d %d", &length[0], &length[1], &length[2]);
		if (length[0] == 0 && length[1] == 0 && length[2] == 0)
			break;
		std::sort(length, length + 3);
		if (length[2] * length[2] == length[0] * length[0] + length[1] * length[1])
			printf("right\n");
		else
			printf("wrong\n");
	}
}