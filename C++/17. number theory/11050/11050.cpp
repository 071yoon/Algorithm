#include <stdio.h>
#include <algorithm>

int main(){
	int num1, num2, ret;

	ret = 1;
	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num2; i++){
		ret *= num1;
		num1--;
	}
	int org_num2 = num2;
	for (int i = 0; i < org_num2; i++){
		ret /= num2;
		num2--;
	}
	printf("%d", ret);
}