#include <stdio.h>
#include <algorithm>

int contains(int num){
	int c;

	while (num){
		if (num % 10 == 6){
			if ((num / 10) % 10 == 6){
				if ((num / 100) % 10 == 6)
					return (1);
			} 
		}
		num /= 10;
	}
	return (0);
}

int main(){
	int i = 0;
	int cnt = 0;
	int num;

	scanf("%d", &num);
	while (true){
		if (contains(i)){
			cnt++;
			if (cnt == num){
				printf("%d", i);
				break;
			}
		}
		i++;
	}
}