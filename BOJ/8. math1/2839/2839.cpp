#include <stdio.h>

int main(){
	int total, five, three, left;
	int cnt;

	scanf("%d", &total);
	five = total / 5;
	three = total % 5;
	if (three == 0){
		printf("%d", five);
		return (0);
	}
	else if (three == 3){
		printf("%d", five + 1);
		return (0);
	}
	else{
		while (five > 0){
			five--;
			three += 5;
			if (three % 3 == 0){
				printf("%d", five + (three / 3));
				return (0);
			}
		}
		printf("-1");
		return (0);
	}
}