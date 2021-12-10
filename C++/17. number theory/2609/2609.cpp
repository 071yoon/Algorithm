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

int lcm(int a, int b, int max)
{
    return (a * b) / max;
}

int main()
{
    int num1, num2;
	
	scanf("%d %d", &num1, &num2);
    int max = gcd(num1, num2);
    int min = lcm(num1, num2, max);
	printf("%d\n%d", max, min);
}