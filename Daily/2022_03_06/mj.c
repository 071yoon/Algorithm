#include <stdio.h>

int main(){
	int num = 0;
	while(1){
		printf("hello");
		num++;
		if (num > 10){
			printf("\n"); //BUFFER 쌓인거 초기화
			while(1){
			}
		}
	}
}

/*

printf, scanf -> enter 기준으로 buffer에 저장을함
scanf -> 'asldkfjlaskdjf'
scanf -> 'asldkfjlaskdjfalskdfj\n' BUFFER -> '\n'

*/
