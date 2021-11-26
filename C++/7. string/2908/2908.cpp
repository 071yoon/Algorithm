#include <stdio.h>

void print_updown(char *arr){
	for (int i = 0; i < 3; i++)
		printf("%c", arr[2 - i]);
}

int main(){
	char first[4] = {0};
	char second[4] = {0};

	scanf("%s", first);
	scanf("%s", second);
	if (first[2] > second[2])
		print_updown(first);
	else if (first[2] < second[2])
		print_updown(second);
	else if (first[1] > second[1])
		print_updown(first);
	else if (first[1] < second[1])
		print_updown(second);
	else if (first[0] > second[0])
		print_updown(first);
	else if (first[0] < second[0])
		print_updown(second);
}