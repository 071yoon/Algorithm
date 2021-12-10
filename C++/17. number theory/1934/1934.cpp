#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int num1, num2, cnt;

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d %d", &num1, &num2);
		int max = gcd(num1, num2);
		printf("%d\n", (num1 * num2) / max);
	}
}