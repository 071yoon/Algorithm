#include <iostream>
#include <stdio.h>

using namespace std;
int main(){
	int	cnt, A, B;

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d + %d = %d\n", i+1, A, B, A+B);
	}
}